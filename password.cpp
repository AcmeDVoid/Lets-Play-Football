#include "password.h"
#include <QDebug>

Password::Password()
{
    passHash = "";
}

Password::Password(QString password)
{
    passHash = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha512).toBase64());
}

QString Password::GetPasswordHash() const
{
    return passHash;
}

bool Password::operator ==(Password comparator) const
{
    return (comparator.GetPasswordHash() == passHash);
}

void Password::SetPassword(QString password)
{
    passHash = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha512).toBase64());
}
