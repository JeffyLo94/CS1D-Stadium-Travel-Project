/****************************************************************************
** Meta object code from reading C++ file 'userselectionwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../userselectionwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userselectionwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserSelectionWindow_t {
    QByteArrayData data[11];
    char stringdata[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserSelectionWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserSelectionWindow_t qt_meta_stringdata_UserSelectionWindow = {
    {
QT_MOC_LITERAL(0, 0, 19), // "UserSelectionWindow"
QT_MOC_LITERAL(1, 20, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 26), // "on_goOnATripButton_clicked"
QT_MOC_LITERAL(4, 70, 23), // "on_removeButton_clicked"
QT_MOC_LITERAL(5, 94, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(6, 115, 29), // "on_onlyNationalButton_clicked"
QT_MOC_LITERAL(7, 145, 29), // "on_onlyAmericanButton_clicked"
QT_MOC_LITERAL(8, 175, 26), // "on_onlyGrassButton_clicked"
QT_MOC_LITERAL(9, 202, 24), // "on_noGrassButton_clicked"
QT_MOC_LITERAL(10, 227, 21) // "on_pushButton_clicked"

    },
    "UserSelectionWindow\0on_backButton_clicked\0"
    "\0on_goOnATripButton_clicked\0"
    "on_removeButton_clicked\0on_addButton_clicked\0"
    "on_onlyNationalButton_clicked\0"
    "on_onlyAmericanButton_clicked\0"
    "on_onlyGrassButton_clicked\0"
    "on_noGrassButton_clicked\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserSelectionWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserSelectionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserSelectionWindow *_t = static_cast<UserSelectionWindow *>(_o);
        switch (_id) {
        case 0: _t->on_backButton_clicked(); break;
        case 1: _t->on_goOnATripButton_clicked(); break;
        case 2: _t->on_removeButton_clicked(); break;
        case 3: _t->on_addButton_clicked(); break;
        case 4: _t->on_onlyNationalButton_clicked(); break;
        case 5: _t->on_onlyAmericanButton_clicked(); break;
        case 6: _t->on_onlyGrassButton_clicked(); break;
        case 7: _t->on_noGrassButton_clicked(); break;
        case 8: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UserSelectionWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UserSelectionWindow.data,
      qt_meta_data_UserSelectionWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserSelectionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserSelectionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserSelectionWindow.stringdata))
        return static_cast<void*>(const_cast< UserSelectionWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int UserSelectionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
