/****************************************************************************
** Meta object code from reading C++ file 'hallview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Mainwindow/hallview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hallview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HallView_t {
    QByteArrayData data[20];
    char stringdata[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HallView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HallView_t qt_meta_stringdata_HallView = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 20),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 10),
QT_MOC_LITERAL(4, 42, 16),
QT_MOC_LITERAL(5, 59, 8),
QT_MOC_LITERAL(6, 68, 19),
QT_MOC_LITERAL(7, 88, 7),
QT_MOC_LITERAL(8, 96, 4),
QT_MOC_LITERAL(9, 101, 10),
QT_MOC_LITERAL(10, 112, 7),
QT_MOC_LITERAL(11, 120, 19),
QT_MOC_LITERAL(12, 140, 7),
QT_MOC_LITERAL(13, 148, 20),
QT_MOC_LITERAL(14, 169, 16),
QT_MOC_LITERAL(15, 186, 8),
QT_MOC_LITERAL(16, 195, 21),
QT_MOC_LITERAL(17, 217, 18),
QT_MOC_LITERAL(18, 236, 7),
QT_MOC_LITERAL(19, 244, 18)
    },
    "HallView\0selectedSeatsChanged\0\0"
    "QList<int>\0getSelectedSeats\0getSeats\0"
    "QList<QList<bool> >\0setRows\0rows\0"
    "setColumns\0columns\0setNumberOfSelected\0"
    "setMode\0comfirmSelectedSeats\0"
    "setSeperateSeats\0seperate\0"
    "getTotalNumberOfSeats\0clearSelectedSeats\0"
    "setHall\0QList<QList<int> >"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HallView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   77,    2, 0x0a /* Public */,
       5,    0,   78,    2, 0x0a /* Public */,
       7,    1,   79,    2, 0x0a /* Public */,
       9,    1,   82,    2, 0x0a /* Public */,
      11,    1,   85,    2, 0x0a /* Public */,
      12,    1,   88,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x0a /* Public */,
      14,    1,   92,    2, 0x0a /* Public */,
      16,    0,   95,    2, 0x0a /* Public */,
      17,    0,   96,    2, 0x0a /* Public */,
      18,    3,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    0x80000000 | 3,
    0x80000000 | 6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, QMetaType::Int, QMetaType::Int,    2,    8,   10,

       0        // eod
};

void HallView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HallView *_t = static_cast<HallView *>(_o);
        switch (_id) {
        case 0: _t->selectedSeatsChanged((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 1: { QList<int> _r = _t->getSelectedSeats();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = _r; }  break;
        case 2: { QList<QList<bool> > _r = _t->getSeats();
            if (_a[0]) *reinterpret_cast< QList<QList<bool> >*>(_a[0]) = _r; }  break;
        case 3: _t->setRows((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setColumns((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setNumberOfSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->comfirmSelectedSeats(); break;
        case 8: _t->setSeperateSeats((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: { int _r = _t->getTotalNumberOfSeats();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: _t->clearSelectedSeats(); break;
        case 11: _t->setHall((*reinterpret_cast< QList<QList<int> >(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HallView::*_t)(QList<int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HallView::selectedSeatsChanged)) {
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void HallView::selectedSeatsChanged(QList<int> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
