/****************************************************************************
** Meta object code from reading C++ file 'LoginDlg.h'
**
** Created: Sun Jul 30 11:31:17 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "LoginDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LoginDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      23,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LoginDlg[] = {
    "LoginDlg\0\0onAccepted()\0onRejected()\0"
};

void LoginDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LoginDlg *_t = static_cast<LoginDlg *>(_o);
        switch (_id) {
        case 0: _t->onAccepted(); break;
        case 1: _t->onRejected(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LoginDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LoginDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LoginDlg,
      qt_meta_data_LoginDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LoginDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LoginDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LoginDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoginDlg))
        return static_cast<void*>(const_cast< LoginDlg*>(this));
    if (!strcmp(_clname, "Ui::LoginDlg"))
        return static_cast< Ui::LoginDlg*>(const_cast< LoginDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int LoginDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
