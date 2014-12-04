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
    QByteArrayData data[16];
    char stringdata[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_popup_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_popup_t qt_meta_stringdata_popup = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 9),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 5),
QT_MOC_LITERAL(4, 23, 8),
QT_MOC_LITERAL(5, 32, 3),
QT_MOC_LITERAL(6, 36, 4),
QT_MOC_LITERAL(7, 41, 5),
QT_MOC_LITERAL(8, 47, 4),
QT_MOC_LITERAL(9, 52, 11),
QT_MOC_LITERAL(10, 64, 25),
QT_MOC_LITERAL(11, 90, 18),
QT_MOC_LITERAL(12, 109, 23),
QT_MOC_LITERAL(13, 133, 28),
QT_MOC_LITERAL(14, 162, 20),
QT_MOC_LITERAL(15, 183, 24)
    },
    "popup\0add_Movie\0\0title\0playtime\0age\0"
    "desc\0genre\0year\0movieposter\0"
    "on_AddGenreButton_clicked\0updateCurrentGenre\0"
    "on_CancelButton_clicked\0"
    "on_RemoveGenreButton_clicked\0"
    "on_AddButton_clicked\0on_ExploreButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_popup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   64,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,
      12,    0,   68,    2, 0x08 /* Private */,
      13,    0,   69,    2, 0x08 /* Private */,
      14,    0,   70,    2, 0x08 /* Private */,
      15,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    4,    5,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void popup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        popup *_t = static_cast<popup *>(_o);
        switch (_id) {
        case 0: _t->add_Movie((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 1: _t->on_AddGenreButton_clicked(); break;
        case 2: _t->updateCurrentGenre((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_CancelButton_clicked(); break;
        case 4: _t->on_RemoveGenreButton_clicked(); break;
        case 5: _t->on_AddButton_clicked(); break;
        case 6: _t->on_ExploreButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (popup::*_t)(QString , int , int , QString , QString , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&popup::add_Movie)) {
                *result = 0;
            }
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void popup::add_Movie(QString _t1, int _t2, int _t3, QString _t4, QString _t5, int _t6, QString _t7)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
