/****************************************************************************
** Meta object code from reading C++ file 'hallview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../HallView/hallview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hallview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HallView_t {
    QByteArrayData data[8];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HallView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HallView_t qt_meta_stringdata_HallView = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 17),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 9),
QT_MOC_LITERAL(4, 38, 7),
QT_MOC_LITERAL(5, 46, 4),
QT_MOC_LITERAL(6, 51, 10),
QT_MOC_LITERAL(7, 62, 7)
    },
    "HallView\0characterSelected\0\0character\0"
    "setRows\0rows\0setColumns\0columns"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HallView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void HallView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HallView *_t = static_cast<HallView *>(_o);
        switch (_id) {
        case 0: _t->characterSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setRows((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setColumns((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HallView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HallView::characterSelected)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HallView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HallView.data,
      qt_meta_data_HallView,  qt_static_metacall, 0, 0}
};


const QMetaObject *HallView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HallView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HallView.stringdata))
        return static_cast<void*>(const_cast< HallView*>(this));
    return QWidget::qt_metacast(_clname);
}

int HallView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HallView::characterSelected(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
