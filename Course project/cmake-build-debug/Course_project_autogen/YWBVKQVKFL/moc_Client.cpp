/****************************************************************************
** Meta object code from reading C++ file 'Client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Client/Client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[19];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 17), // "characterReceived"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "Character"
QT_MOC_LITERAL(4, 36, 17), // "broadcastReceived"
QT_MOC_LITERAL(5, 54, 13), // "traitReceived"
QT_MOC_LITERAL(6, 68, 10), // "madeNoTurn"
QT_MOC_LITERAL(7, 79, 12), // "voteReceived"
QT_MOC_LITERAL(8, 92, 12), // "turnReceived"
QT_MOC_LITERAL(9, 105, 13), // "votingStarted"
QT_MOC_LITERAL(10, 119, 9), // "connected"
QT_MOC_LITERAL(11, 129, 15), // "broadcastHandle"
QT_MOC_LITERAL(12, 145, 11), // "traitHandle"
QT_MOC_LITERAL(13, 157, 13), // "connectToHost"
QT_MOC_LITERAL(14, 171, 10), // "ip_address"
QT_MOC_LITERAL(15, 182, 16), // "sendTraitOverUdp"
QT_MOC_LITERAL(16, 199, 5), // "trait"
QT_MOC_LITERAL(17, 205, 8), // "sendVote"
QT_MOC_LITERAL(18, 214, 12) // "voted_number"

    },
    "Client\0characterReceived\0\0Character\0"
    "broadcastReceived\0traitReceived\0"
    "madeNoTurn\0voteReceived\0turnReceived\0"
    "votingStarted\0connected\0broadcastHandle\0"
    "traitHandle\0connectToHost\0ip_address\0"
    "sendTraitOverUdp\0trait\0sendVote\0"
    "voted_number"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       4,    1,   84,    2, 0x06 /* Public */,
       5,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,
       7,    1,   93,    2, 0x06 /* Public */,
       8,    0,   96,    2, 0x06 /* Public */,
       9,    0,   97,    2, 0x06 /* Public */,
      10,    0,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    1,  101,    2, 0x0a /* Public */,
      15,    1,  104,    2, 0x0a /* Public */,
      17,    1,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Client *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->characterReceived((*reinterpret_cast< Character(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->broadcastReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->traitReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->madeNoTurn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->voteReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->turnReceived(); break;
        case 6: _t->votingStarted(); break;
        case 7: _t->connected(); break;
        case 8: _t->broadcastHandle(); break;
        case 9: _t->traitHandle(); break;
        case 10: _t->connectToHost((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->sendTraitOverUdp((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->sendVote((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Client::*)(Character , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::characterReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::broadcastReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::traitReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Client::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::madeNoTurn)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Client::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::voteReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::turnReceived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::votingStarted)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::connected)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Client.data,
    qt_meta_data_Client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Client::characterReceived(Character _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Client::broadcastReceived(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Client::traitReceived(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Client::madeNoTurn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Client::voteReceived(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Client::turnReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Client::votingStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Client::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
