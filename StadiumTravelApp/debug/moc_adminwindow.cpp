/****************************************************************************
** Meta object code from reading C++ file 'adminwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../adminwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_adminwindow_t {
    QByteArrayData data[15];
    char stringdata[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_adminwindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_adminwindow_t qt_meta_stringdata_adminwindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "adminwindow"
QT_MOC_LITERAL(1, 12, 18), // "on_backBtn_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 43), // "on_leagueSelectComboBox_curre..."
QT_MOC_LITERAL(4, 76, 5), // "index"
QT_MOC_LITERAL(5, 82, 21), // "on_addStadBtn_clicked"
QT_MOC_LITERAL(6, 104, 34), // "on_stadiumSelectWidget_itemCl..."
QT_MOC_LITERAL(7, 139, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 156, 4), // "item"
QT_MOC_LITERAL(9, 161, 38), // "on_countryComboBox_currentInd..."
QT_MOC_LITERAL(10, 200, 18), // "on_saveBtn_clicked"
QT_MOC_LITERAL(11, 219, 20), // "on_updateBtn_clicked"
QT_MOC_LITERAL(12, 240, 20), // "on_addNewBtn_clicked"
QT_MOC_LITERAL(13, 261, 21), // "on_deleteSouv_clicked"
QT_MOC_LITERAL(14, 283, 24) // "on_addNewStadBtn_clicked"

    },
    "adminwindow\0on_backBtn_clicked\0\0"
    "on_leagueSelectComboBox_currentIndexChanged\0"
    "index\0on_addStadBtn_clicked\0"
    "on_stadiumSelectWidget_itemClicked\0"
    "QListWidgetItem*\0item\0"
    "on_countryComboBox_currentIndexChanged\0"
    "on_saveBtn_clicked\0on_updateBtn_clicked\0"
    "on_addNewBtn_clicked\0on_deleteSouv_clicked\0"
    "on_addNewStadBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_adminwindow[] = {

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
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    1,   69,    2, 0x08 /* Private */,
       9,    1,   72,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,
      13,    0,   78,    2, 0x08 /* Private */,
      14,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void adminwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        adminwindow *_t = static_cast<adminwindow *>(_o);
        switch (_id) {
        case 0: _t->on_backBtn_clicked(); break;
        case 1: _t->on_leagueSelectComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_addStadBtn_clicked(); break;
        case 3: _t->on_stadiumSelectWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_countryComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_saveBtn_clicked(); break;
        case 6: _t->on_updateBtn_clicked(); break;
        case 7: _t->on_addNewBtn_clicked(); break;
        case 8: _t->on_deleteSouv_clicked(); break;
        case 9: _t->on_addNewStadBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject adminwindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_adminwindow.data,
      qt_meta_data_adminwindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *adminwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *adminwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_adminwindow.stringdata))
        return static_cast<void*>(const_cast< adminwindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int adminwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
