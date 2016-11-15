#ifndef PASSWORD_H
#define PASSWORD_H
#include <QString>
#include <QCryptographicHash>

/*!
 * \brief The Password class
 * Container class for a QString used for hashing + salting for passwords.
 *
 * This class is a container for a QCryptographicHash containing the password, salted with the username.
 * How it's calculated: SHA3-512( Password + Username)
 * Both QStrings are converted into their raw data value as UTF-8 characters.
 * the reason we add the password to the username is that so 2 users with the same password will not have the same hash.
 * This is called salting.
 *
 * Encryption method - SHA3-512. Latest high security hashing algorithm not vulnerable to collision.
 * The password is not stored inside this OR ANY OTHER CLASS. Instead, this class will only know wheter
 * what the user inputted was in fact the same password as the original one.
 *
 * This function is ONE-WAY, meaning there is no method to get the password back from the hash.
 */
class Password
{
public:
    /*!
     * \brief Password
     * Default constructor: creates an empty password hash (DIFFERENT FROM HASHING NULL.)
     */
    Password();

    /*!
     * \brief Password
     * Nondefault constructor: salts the username and password and generates a hash.
     *
     * \param username
     * Secondary parameter for salt. Not stored local.
     *
     * \param password
     * Primary parameter for salt. Not stored local.
     */
    Password(QString password);

    /*!
     * \brief GetPasswordHash
     * Returns the hash saved as a string.
     * \return
     */
    QString GetPasswordHash() const;

    /*!
     * \brief SetPassword
     * Generate a hash using the provided parameters. Converts hash: QByteStream > QByteStream<base64> > QString.
     * \param username
     * \param password
     */
    void SetPassword(QString password);

    /*!
     * \brief operator ==
     * Provided an instance of a Password object, this class will compare the local hash to the provided hash.
     * This algorithm is cryptographically secure, meaning deviation in a single bit will generate an entirely
     * different hash. There are no "off by ones".
     *
     * \param comparator
     * instance of the Password class to compare to
     *
     * \return
     */
    bool operator==(Password comparator) const;

    void SetRawHash(QString rawpass)
    {
        passHash = rawpass;
    }

private:
    QString passHash;
};


#endif // PASSWORD_H
