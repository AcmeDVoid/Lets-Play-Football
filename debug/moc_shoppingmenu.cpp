/****************************************************************************
** Meta object code from reading C++ file 'shoppingmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/shoppingmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shoppingmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_shoppingMenu_t {
    QByteArrayData data[10];
    char stringdata[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_shoppingMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_shoppingMenu_t qt_meta_stringdata_shoppingMenu = {
    {
QT_MOC_LITERAL(0, 0, 12), // "shoppingMenu"
QT_MOC_LITERAL(1, 13, 15), // "on_next_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "on_prev_clicked"
QT_MOC_LITERAL(4, 46, 20), // "on_addToCart_clicked"
QT_MOC_LITERAL(5, 67, 14), // "modifyCartItem"
QT_MOC_LITERAL(6, 82, 8), // "QAction*"
QT_MOC_LITERAL(7, 91, 34), // "on_cart_customContextMenuRequ..."
QT_MOC_LITERAL(8, 126, 3), // "pos"
QT_MOC_LITERAL(9, 130, 23) // "on_okay_cancel_accepted"

    },
    "shoppingMenu\0on_next_clicked\0\0"
    "on_prev_clicked\0on_addToCart_clicked\0"
    "modifyCartItem\0QAction*\0"
    "on_cart_customContextMenuRequested\0"
    "pos\0on_okay_cancel_accepted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_shoppingMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void,

       0        // eod
};

void shoppingMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        shoppingMenu *_t = static_cast<shoppingMenu *>(_o);
        switch (_id) {
        case 0: _t->on_next_clicked(); break;
        case 1: _t->on_prev_clicked(); break;
        case 2: _t->on_addToCart_clicked(); break;
        case 3: _t->modifyCartItem((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: _t->on_cart_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 5: _t->on_okay_cancel_accepted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject shoppingMenu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_shoppingMenu.data,
      qt_meta_data_shoppingMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *shoppingMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *shoppingMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_shoppingMenu.stringdata))
        return static_cast<void*>(const_cast< shoppingMenu*>(this));
    return QDialog::qt_metacast(_clname);
}

int shoppingMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
