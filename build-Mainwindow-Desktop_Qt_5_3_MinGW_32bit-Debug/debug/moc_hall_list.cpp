/****************************************************************************
** Meta object code from reading C++ file 'hall_list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Mainwindow/hall_list/hall_list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hall_list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_hall_list_t {
    QByteArrayData data[17];
    char stringdata[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hall_list_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hall_list_t qt_meta_stringdata_hall_list = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 21),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 20),
QT_MOC_LITERAL(4, 54, 14),
QT_MOC_LITERAL(5, 69, 8),
QT_MOC_LITERAL(6, 78, 10),
QT_MOC_LITERAL(7, 89, 10),
QT_MOC_LITERAL(8, 100, 20),
QT_MOC_LITERAL(9, 121, 8),
QT_MOC_LITERAL(10, 130, 6),
QT_MOC_LITERAL(11, 137, 4),
QT_MOC_LITERAL(12, 142, 10),
QT_MOC_LITERAL(13, 153, 11),
QT_MOC_LITERAL(14, 165, 19),
QT_MOC_LITERAL(15, 185, 5),
QT_MOC_LITERAL(16, 191, 22)
    },
    "hall_list\0setLabelNumberOfSeats\0\0"
    "hallSelectionChanged\0QItemSelection\0"
    "selected\0deselected\0deleteHall\0"
    "openEditHallDialogue\0editHall\0hallID\0"
    "name\0screenSize\0soundSystem\0"
    "QList<QList<bool> >\0seats\0"
    "on_CloseButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hall_list[] = {

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
       3,    2,   45,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,
       9,    5,   52,    2, 0x08 /* Private */,
      16,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 14,   10,   11,   12,   13,   15,
    QMetaType::Void,

       0        // eod
};

void hall_list::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hall_list *_t = static_cast<hall_list *>(_o);
        switch (_id) {
        case 0: _t->setLabelNumberOfSeats(); break;
        case 1: _t->hallSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 2: _t->deleteHall(); break;
        case 3: _t->openEditHallDialogue(); break;
        case 4: _t->editHall((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QList<QList<bool> >(*)>(_a[5]))); break;
        case 5: _t->on_CloseButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<bool> > >(); break;
            }
            break;
        }
    }
}

const QMetaObject hall_list::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_hall_list.data,
      qt_meta_data_hall_list,  qt_static_metacall, 0, 0}
};


const QMetaObject *hall_list::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hall_list::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_hall_list.stringdata))
        return static_cast<void*>(const_cast< hall_list*>(this));
    return QDialog::qt_metacast(_clname);
}

int hall_list::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
