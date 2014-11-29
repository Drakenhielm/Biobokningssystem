/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Mainwindow/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata[578];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 21),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 14),
QT_MOC_LITERAL(4, 49, 8),
QT_MOC_LITERAL(5, 58, 10),
QT_MOC_LITERAL(6, 69, 20),
QT_MOC_LITERAL(7, 90, 23),
QT_MOC_LITERAL(8, 114, 31),
QT_MOC_LITERAL(9, 146, 32),
QT_MOC_LITERAL(10, 179, 35),
QT_MOC_LITERAL(11, 215, 26),
QT_MOC_LITERAL(12, 242, 5),
QT_MOC_LITERAL(13, 248, 28),
QT_MOC_LITERAL(14, 277, 30),
QT_MOC_LITERAL(15, 308, 33),
QT_MOC_LITERAL(16, 342, 28),
QT_MOC_LITERAL(17, 371, 7),
QT_MOC_LITERAL(18, 379, 11),
QT_MOC_LITERAL(19, 391, 20),
QT_MOC_LITERAL(20, 412, 14),
QT_MOC_LITERAL(21, 427, 40),
QT_MOC_LITERAL(22, 468, 38),
QT_MOC_LITERAL(23, 507, 34),
QT_MOC_LITERAL(24, 542, 30),
QT_MOC_LITERAL(25, 573, 4)
    },
    "MainWindow\0movieSelectionChanged\0\0"
    "QItemSelection\0selected\0deselected\0"
    "showSelectionChanged\0on_actionQuit_triggered\0"
    "on_pushButton_info_edit_clicked\0"
    "on_pushButton_movies_add_clicked\0"
    "on_pushButton_movies_delete_clicked\0"
    "on_listView_movies_clicked\0index\0"
    "on_listView_movies_activated\0"
    "on_pushButton_show_add_clicked\0"
    "on_pushButton_show_delete_clicked\0"
    "on_pushButton_search_clicked\0setHTML\0"
    "getSelected\0QItemSelectionModel*\0"
    "selectionModel\0on_pushButton_hallview_info_book_clicked\0"
    "on_comboBox_search_currentIndexChanged\0"
    "on_lineEdit_search_editingFinished\0"
    "on_lineEdit_search_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x08 /* Private */,
       6,    2,  104,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    1,  113,    2, 0x08 /* Private */,
      13,    1,  116,    2, 0x08 /* Private */,
      14,    0,  119,    2, 0x08 /* Private */,
      15,    0,  120,    2, 0x08 /* Private */,
      16,    0,  121,    2, 0x08 /* Private */,
      17,    0,  122,    2, 0x08 /* Private */,
      18,    1,  123,    2, 0x08 /* Private */,
      21,    0,  126,    2, 0x08 /* Private */,
      22,    1,  127,    2, 0x08 /* Private */,
      23,    0,  130,    2, 0x08 /* Private */,
      24,    1,  131,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->movieSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 1: _t->showSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 2: _t->on_actionQuit_triggered(); break;
        case 3: _t->on_pushButton_info_edit_clicked(); break;
        case 4: _t->on_pushButton_movies_add_clicked(); break;
        case 5: _t->on_pushButton_movies_delete_clicked(); break;
        case 6: _t->on_listView_movies_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_listView_movies_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_show_add_clicked(); break;
        case 9: _t->on_pushButton_show_delete_clicked(); break;
        case 10: _t->on_pushButton_search_clicked(); break;
        case 11: _t->setHTML(); break;
        case 12: { int _r = _t->getSelected((*reinterpret_cast< QItemSelectionModel*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: _t->on_pushButton_hallview_info_book_clicked(); break;
        case 14: _t->on_comboBox_search_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelectionModel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
