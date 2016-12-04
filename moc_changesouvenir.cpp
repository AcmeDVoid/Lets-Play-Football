/****************************************************************************
** Meta object code from reading C++ file 'changesouvenir.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/changesouvenir.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changesouvenir.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_changesouvenir_t {
    QByteArrayData data[15];
    char stringdata[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_changesouvenir_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_changesouvenir_t qt_meta_stringdata_changesouvenir = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 36),
QT_MOC_LITERAL(2, 52, 0),
QT_MOC_LITERAL(3, 53, 5),
QT_MOC_LITERAL(4, 59, 32),
QT_MOC_LITERAL(5, 92, 3),
QT_MOC_LITERAL(6, 96, 6),
QT_MOC_LITERAL(7, 103, 12),
QT_MOC_LITERAL(8, 116, 22),
QT_MOC_LITERAL(9, 139, 12),
QT_MOC_LITERAL(10, 152, 15),
QT_MOC_LITERAL(11, 168, 17),
QT_MOC_LITERAL(12, 186, 9),
QT_MOC_LITERAL(13, 196, 23),
QT_MOC_LITERAL(14, 220, 20)
    },
    "changesouvenir\0on_selectStadium_currentIndexChanged\0"
    "\0index\0on_souvenirEditTable_cellChanged\0"
    "row\0column\0detectChange\0on_addSouvenir_clicked\0"
    "tableIsValid\0on_save_clicked\0"
    "on_cancel_clicked\0saveTable\0"
    "on_deleteButton_clicked\0deleteRequestIsValid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_changesouvenir[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    2,   67,    2, 0x08 /* Private */,
       7,    1,   72,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void changesouvenir::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        changesouvenir *_t = static_cast<changesouvenir *>(_o);
        switch (_id) {
        case 0: _t->on_selectStadium_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_souvenirEditTable_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->detectChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_addSouvenir_clicked(); break;
        case 4: { bool _r = _t->tableIsValid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->on_save_clicked(); break;
        case 6: _t->on_cancel_clicked(); break;
        case 7: _t->saveTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_deleteButton_clicked(); break;
        case 9: { bool _r = _t->deleteRequestIsValid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject changesouvenir::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_changesouvenir.data,
      qt_meta_data_changesouvenir,  qt_static_metacall, 0, 0}
};


const QMetaObject *changesouvenir::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *changesouvenir::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_changesouvenir.stringdata))
        return static_cast<void*>(const_cast< changesouvenir*>(this));
    return QDialog::qt_metacast(_clname);
}

int changesouvenir::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
