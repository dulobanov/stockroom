/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created: Sat Jul 21 13:07:12 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/login.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_login[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      23,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,    6,    6,    6, 0x0a,
      45,    6,    6,    6, 0x0a,
      58,   54,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_login[] = {
    "login\0\0login_success()\0login_fail()\0"
    "accept()\0reject()\0tab\0tab_switched(int)\0"
};

void login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        login *_t = static_cast<login *>(_o);
        switch (_id) {
        case 0: _t->login_success(); break;
        case 1: _t->login_fail(); break;
        case 2: _t->accept(); break;
        case 3: _t->reject(); break;
        case 4: _t->tab_switched((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData login::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject login::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_login,
      qt_meta_data_login, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &login::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *login::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_login))
        return static_cast<void*>(const_cast< login*>(this));
    return QDialog::qt_metacast(_clname);
}

int login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void login::login_success()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void login::login_fail()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
