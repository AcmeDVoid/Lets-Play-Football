/****************************************************************************
** Meta object code from reading C++ file 'addstadium.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/addstadium.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addstadium.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_addstadium_t {
    QByteArrayData data[9];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addstadium_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addstadium_t qt_meta_stringdata_addstadium = {
    {
QT_MOC_LITERAL(0, 0, 10), // "addstadium"
QT_MOC_LITERAL(1, 11, 26), // "on_addSouvenirItem_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 27), // "on_addStadiumButton_clicked"
QT_MOC_LITERAL(4, 67, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(5, 91, 35), // "on_comboBoxEdge_currentIndexC..."
QT_MOC_LITERAL(6, 127, 5), // "index"
QT_MOC_LITERAL(7, 133, 27), // "on_spinnerEdge_valueChanged"
QT_MOC_LITERAL(8, 161, 4) // "arg1"

    },
    "addstadium\0on_addSouvenirItem_clicked\0"
    "\0on_addStadiumButton_clicked\0"
    "on_cancelButton_clicked\0"
    "on_comboBoxEdge_currentIndexChanged\0"
    "index\0on_spinnerEdge_valueChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addstadium[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void addstadium::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addstadium *_t = static_cast<addstadium *>(_o);
        switch (_id) {
        case 0: _t->on_addSouvenirItem_clicked(); break;
        case 1: _t->on_addStadiumButton_clicked(); break;
        case 2: _t->on_cancelButton_clicked(); break;
//        case 3: _t->on_comboBoxEdge_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
//        case 4: _t->on_spinnerEdge_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject addstadium::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addstadium.data,
      qt_meta_data_addstadium,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *addstadium::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addstadium::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_addstadium.stringdata))
        return static_cast<void*>(const_cast< addstadium*>(this));
    return QDialog::qt_metacast(_clname);
}

int addstadium::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
