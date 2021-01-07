/****************************************************************************
** Meta object code from reading C++ file 'user.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../airport/user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_user_t {
    const uint offsetsAndSize[24];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_user_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_user_t qt_meta_stringdata_user = {
    {
QT_MOC_LITERAL(0, 4), // "user"
QT_MOC_LITERAL(5, 21), // "on_backChoose_clicked"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 23), // "on_confirm_Book_clicked"
QT_MOC_LITERAL(52, 4), // "Book"
QT_MOC_LITERAL(57, 25), // "on_confirm_Refund_clicked"
QT_MOC_LITERAL(83, 6), // "Refund"
QT_MOC_LITERAL(90, 24), // "on_confirm_Check_clicked"
QT_MOC_LITERAL(115, 5), // "Check"
QT_MOC_LITERAL(121, 16), // "on_bookT_clicked"
QT_MOC_LITERAL(138, 18), // "on_refundT_clicked"
QT_MOC_LITERAL(157, 17) // "on_checkT_clicked"

    },
    "user\0on_backChoose_clicked\0\0"
    "on_confirm_Book_clicked\0Book\0"
    "on_confirm_Refund_clicked\0Refund\0"
    "on_confirm_Check_clicked\0Check\0"
    "on_bookT_clicked\0on_refundT_clicked\0"
    "on_checkT_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_user[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    0 /* Private */,
       3,    0,   75,    2, 0x08,    1 /* Private */,
       4,    0,   76,    2, 0x08,    2 /* Private */,
       5,    0,   77,    2, 0x08,    3 /* Private */,
       6,    0,   78,    2, 0x08,    4 /* Private */,
       7,    0,   79,    2, 0x08,    5 /* Private */,
       8,    0,   80,    2, 0x08,    6 /* Private */,
       9,    0,   81,    2, 0x08,    7 /* Private */,
      10,    0,   82,    2, 0x08,    8 /* Private */,
      11,    0,   83,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void user::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<user *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_backChoose_clicked(); break;
        case 1: _t->on_confirm_Book_clicked(); break;
        case 2: _t->Book(); break;
        case 3: _t->on_confirm_Refund_clicked(); break;
        case 4: _t->Refund(); break;
        case 5: _t->on_confirm_Check_clicked(); break;
        case 6: _t->Check(); break;
        case 7: _t->on_bookT_clicked(); break;
        case 8: _t->on_refundT_clicked(); break;
        case 9: _t->on_checkT_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject user::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_user.offsetsAndSize,
    qt_meta_data_user,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_user_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *user::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *user::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_user.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int user::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
