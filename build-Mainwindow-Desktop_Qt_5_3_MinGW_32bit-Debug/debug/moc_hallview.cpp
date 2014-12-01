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
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hallview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HallView_t {
    QByteArrayData data[10];
    char stringdata[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HallView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HallView_t qt_meta_stringdata_HallView = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 16),
QT_MOC_LITERAL(2, 26, 16),
QT_MOC_LITERAL(3, 43, 0),
QT_MOC_LITERAL(4, 44, 7),
QT_MOC_LITERAL(5, 52, 4),
QT_MOC_LITERAL(6, 57, 10),
QT_MOC_LITERAL(7, 68, 7),
QT_MOC_LITERAL(8, 76, 19),
QT_MOC_LITERAL(9, 96, 7)
    },
    "HallView\0getSelectedSeats\0std::vector<int>\0"
    "\0setRows\0rows\0setColumns\0columns\0"
    "setNumberOfSelected\0setMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HallView[] = {

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
       1,    0,   39,    3, 0x0a /* Public */,
       4,    1,   40,    3, 0x0a /* Public */,
       6,    1,   43,    3, 0x0a /* Public */,
       8,    1,   46,    3, 0x0a /* Public */,
       9,    1,   49,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void HallView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HallView *_t = static_cast<HallView *>(_o);
        switch (_id) {
        case 0: { std::vector<int> _r = _t->getSelectedSeats();
            if (_a[0]) *reinterpret_cast< std::vector<int>*>(_a[0]) = _r; }  break;
        case 1: _t->setRows((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setColumns((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setNumberOfSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
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
