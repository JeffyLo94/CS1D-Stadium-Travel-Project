/****************************************************************************
** Meta object code from reading C++ file 'purchase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../purchase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'purchase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Purchase_t {
    QByteArrayData data[7];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Purchase_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Purchase_t qt_meta_stringdata_Purchase = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Purchase"
QT_MOC_LITERAL(1, 9, 20), // "on_addToCart_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 25), // "on_removeFromCart_clicked"
QT_MOC_LITERAL(4, 57, 15), // "on_next_clicked"
QT_MOC_LITERAL(5, 73, 23), // "on_prev_stadium_clicked"
QT_MOC_LITERAL(6, 97, 25) // "on_backToTripType_clicked"

    },
    "Purchase\0on_addToCart_clicked\0\0"
    "on_removeFromCart_clicked\0on_next_clicked\0"
    "on_prev_stadium_clicked\0"
    "on_backToTripType_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Purchase[] = {

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
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Purchase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Purchase *_t = static_cast<Purchase *>(_o);
        switch (_id) {
        case 0: _t->on_addToCart_clicked(); break;
        case 1: _t->on_removeFromCart_clicked(); break;
        case 2: _t->on_next_clicked(); break;
        case 3: _t->on_prev_stadium_clicked(); break;
        case 4: _t->on_backToTripType_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Purchase::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Purchase.data,
      qt_meta_data_Purchase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Purchase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Purchase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Purchase.stringdata))
        return static_cast<void*>(const_cast< Purchase*>(this));
    return QDialog::qt_metacast(_clname);
}

int Purchase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
