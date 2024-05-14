/****************************************************************************
** Meta object code from reading C++ file 'Host.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Host/Host.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Host.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Host_t {
    QByteArrayData data[11];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Host_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Host_t qt_meta_stringdata_Host = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Host"
QT_MOC_LITERAL(1, 5, 14), // "giveTurnToHost"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 16), // "everyoneIsInGame"
QT_MOC_LITERAL(4, 38, 13), // "sendVotingEnd"
QT_MOC_LITERAL(5, 52, 11), // "traitHandle"
QT_MOC_LITERAL(6, 64, 18), // "broadcastTheHostIP"
QT_MOC_LITERAL(7, 83, 17), // "generateCharacter"
QT_MOC_LITERAL(8, 101, 9), // "Character"
QT_MOC_LITERAL(9, 111, 22), // "generateEmptyCharacter"
QT_MOC_LITERAL(10, 134, 11) // "startVoting"

    },
    "Host\0giveTurnToHost\0\0everyoneIsInGame\0"
    "sendVotingEnd\0traitHandle\0broadcastTheHostIP\0"
    "generateCharacter\0Character\0"
    "generateEmptyCharacter\0startVoting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Host[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       9,    0,   60,    2, 0x0a /* Public */,
      10,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 8,
    0x80000000 | 8,
    QMetaType::Void,

       0        // eod
};

void Host::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Host *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->giveTurnToHost(); break;
        case 1: _t->everyoneIsInGame(); break;
        case 2: _t->sendVotingEnd(); break;
        case 3: _t->traitHandle(); break;
        case 4: _t->broadcastTheHostIP(); break;
        case 5: { Character _r = _t->generateCharacter();
            if (_a[0]) *reinterpret_cast< Character*>(_a[0]) = std::move(_r); }  break;
        case 6: { Character _r = _t->generateEmptyCharacter();
            if (_a[0]) *reinterpret_cast< Character*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->startVoting(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Host::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Host::giveTurnToHost)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Host::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Host::everyoneIsInGame)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Host::staticMetaObject = { {
    QMetaObject::SuperData::link<Client::staticMetaObject>(),
    qt_meta_stringdata_Host.data,
    qt_meta_data_Host,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Host::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Host::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Host.stringdata0))
        return static_cast<void*>(this);
    return Client::qt_metacast(_clname);
}

int Host::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Client::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Host::giveTurnToHost()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Host::everyoneIsInGame()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
