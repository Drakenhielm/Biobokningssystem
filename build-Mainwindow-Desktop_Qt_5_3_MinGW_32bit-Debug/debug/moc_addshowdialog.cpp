/****************************************************************************
** Meta object code from reading C++ file 'addshowdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Mainwindow/add_show/addshowdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addshowdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_addShowDialog_t {
    QByteArrayData data[15];
    char stringdata[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addShowDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addShowDialog_t qt_meta_stringdata_addShowDialog = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 8),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 8),
QT_MOC_LITERAL(4, 33, 5),
QT_MOC_LITERAL(5, 39, 4),
QT_MOC_LITERAL(6, 44, 3),
QT_MOC_LITERAL(7, 48, 4),
QT_MOC_LITERAL(8, 53, 7),
QT_MOC_LITERAL(9, 61, 6),
QT_MOC_LITERAL(10, 68, 9),
QT_MOC_LITERAL(11, 78, 6),
QT_MOC_LITERAL(12, 85, 8),
QT_MOC_LITERAL(13, 94, 24),
QT_MOC_LITERAL(14, 119, 27)
    },
    "addShowDialog\0add_Show\0\0datetime\0price\0"
    "lang\0DDD\0subs\0movieID\0hallID\0edit_show\0"
    "showID\0dateTime\0on_addShowButton_clicked\0"
    "on_cancelShowButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addShowDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   34,    2, 0x06 /* Public */,
      10,    8,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   66,    2, 0x08 /* Private */,
      14,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::Double, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QDateTime, QMetaType::Double, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Int, QMetaType::Int,   11,   12,    4,    5,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void addShowDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addShowDialog *_t = static_cast<addShowDialog *>(_o);
        switch (_id) {
        case 0: _t->add_Show((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 1: _t->edit_show((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 2: _t->on_addShowButton_clicked(); break;
        case 3: _t->on_cancelShowButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (addShowDialog::*_t)(QDateTime , double , QString , bool , bool , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&addShowDialog::add_Show)) {
                *result = 0;
            }
        }
        {
            typedef void (addShowDialog::*_t)(int , QDateTime , double , QString , bool , bool , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&addShowDialog::edit_show)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject addShowDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addShowDialog.data,
      qt_meta_data_addShowDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *addShowDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addShowDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addShowDialog.stringdata))
        return static_cast<void*>(const_cast< addShowDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int addShowDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void addShowDialog::add_Show(QDateTime _t1, double _t2, QString _t3, bool _t4, bool _t5, int _t6, int _t7)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void addShowDialog::edit_show(int _t1, QDateTime _t2, double _t3, QString _t4, bool _t5, bool _t6, int _t7, int _t8)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
