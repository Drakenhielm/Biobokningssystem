/****************************************************************************
** Meta object code from reading C++ file 'popup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Mainwindow/add_movie/popup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'popup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_popup_t {
    QByteArrayData data[6];
    char stringdata[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_popup_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_popup_t qt_meta_stringdata_popup = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 25),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 18),
QT_MOC_LITERAL(4, 52, 23),
QT_MOC_LITERAL(5, 76, 28)
    },
    "popup\0on_AddGenreButton_clicked\0\0"
    "updateCurrentGenre\0on_CancelButton_clicked\0"
    "on_RemoveGenreButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_popup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       4,    0,   38,    2, 0x08 /* Private */,
       5,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void popup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        popup *_t = static_cast<popup *>(_o);
        switch (_id) {
        case 0: _t->on_AddGenreButton_clicked(); break;
        case 1: _t->updateCurrentGenre((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_CancelButton_clicked(); break;
        case 3: _t->on_RemoveGenreButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject popup::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_popup.data,
      qt_meta_data_popup,  qt_static_metacall, 0, 0}
};


const QMetaObject *popup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *popup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_popup.stringdata))
        return static_cast<void*>(const_cast< popup*>(this));
    return QDialog::qt_metacast(_clname);
}

int popup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
