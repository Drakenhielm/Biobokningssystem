/****************************************************************************
** Meta object code from reading C++ file 'hallview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Mainwindow/hallview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hallview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HallView_t {
    QByteArrayData data[25];
    char stringdata[317];
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
QT_MOC_LITERAL(7, 88, 21),
QT_MOC_LITERAL(8, 110, 9),
QT_MOC_LITERAL(9, 120, 8),
QT_MOC_LITERAL(10, 129, 11),
QT_MOC_LITERAL(11, 141, 7),
QT_MOC_LITERAL(12, 149, 4),
QT_MOC_LITERAL(13, 154, 10),
QT_MOC_LITERAL(14, 165, 7),
QT_MOC_LITERAL(15, 173, 19),
QT_MOC_LITERAL(16, 193, 7),
QT_MOC_LITERAL(17, 201, 16),
QT_MOC_LITERAL(18, 218, 8),
QT_MOC_LITERAL(19, 227, 7),
QT_MOC_LITERAL(20, 235, 22),
QT_MOC_LITERAL(21, 258, 10),
QT_MOC_LITERAL(22, 269, 7),
QT_MOC_LITERAL(23, 277, 20),
QT_MOC_LITERAL(24, 298, 18)
    },
    "HallView\0selectedSeatsChanged\0\0"
    "QList<int>\0getSelectedSeats\0getSeats\0"
    "QList<QList<bool> >\0getTotalNumberOfSeats\0"
    "getSeatNr\0rowIndex\0columnIndex\0setRows\0"
    "rows\0setColumns\0columns\0setNumberOfSelected\0"
    "setMode\0setSeperateSeats\0seperate\0"
    "setHall\0QVector<QVector<int> >\0"
    "setEnabled\0enabled\0comfirmSelectedSeats\0"
    "clearSelectedSeats"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HallView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   87,    2, 0x0a /* Public */,
       5,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    2,   90,    2, 0x0a /* Public */,
      11,    1,   95,    2, 0x0a /* Public */,
      13,    1,   98,    2, 0x0a /* Public */,
      15,    1,  101,    2, 0x0a /* Public */,
      16,    1,  104,    2, 0x0a /* Public */,
      17,    1,  107,    2, 0x0a /* Public */,
      19,    3,  110,    2, 0x0a /* Public */,
      21,    1,  117,    2, 0x0a /* Public */,
      23,    0,  120,    2, 0x0a /* Public */,
      24,    0,  121,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    0x80000000 | 3,
    0x80000000 | 6,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Int, QMetaType::Int,    2,   12,   14,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void,
    QMetaType::Void,

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
        case 3: { int _r = _t->getTotalNumberOfSeats();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->getSeatNr((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: _t->setRows((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setColumns((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setNumberOfSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setSeperateSeats((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setHall((*reinterpret_cast< QVector<QVector<int> >(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->comfirmSelectedSeats(); break;
        case 13: _t->clearSelectedSeats(); break;
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
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<int> > >(); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
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
