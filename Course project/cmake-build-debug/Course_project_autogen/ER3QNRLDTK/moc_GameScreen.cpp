/****************************************************************************
** Meta object code from reading C++ file 'GameScreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GameScreen/GameScreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameScreen_t {
    QByteArrayData data[18];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameScreen_t qt_meta_stringdata_GameScreen = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameScreen"
QT_MOC_LITERAL(1, 11, 9), // "traitSent"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "turnMade"
QT_MOC_LITERAL(4, 31, 8), // "voteMade"
QT_MOC_LITERAL(5, 40, 20), // "addCharacterToWindow"
QT_MOC_LITERAL(6, 61, 9), // "Character"
QT_MOC_LITERAL(7, 71, 15), // "PlayerCharacter"
QT_MOC_LITERAL(8, 87, 16), // "character_number"
QT_MOC_LITERAL(9, 104, 11), // "changeTrait"
QT_MOC_LITERAL(10, 116, 9), // "sendTrait"
QT_MOC_LITERAL(11, 126, 5), // "trait"
QT_MOC_LITERAL(12, 132, 12), // "sendVoteMade"
QT_MOC_LITERAL(13, 145, 15), // "voted_character"
QT_MOC_LITERAL(14, 161, 7), // "setTurn"
QT_MOC_LITERAL(15, 169, 16), // "enableVoteButton"
QT_MOC_LITERAL(16, 186, 11), // "changeVotes"
QT_MOC_LITERAL(17, 198, 16) // "turnToNextScreen"

    },
    "GameScreen\0traitSent\0\0turnMade\0voteMade\0"
    "addCharacterToWindow\0Character\0"
    "PlayerCharacter\0character_number\0"
    "changeTrait\0sendTrait\0trait\0sendVoteMade\0"
    "voted_character\0setTurn\0enableVoteButton\0"
    "changeVotes\0turnToNextScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameScreen[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    0,   72,    2, 0x06 /* Public */,
       4,    1,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   76,    2, 0x0a /* Public */,
       9,    1,   81,    2, 0x0a /* Public */,
      10,    1,   84,    2, 0x0a /* Public */,
      12,    1,   87,    2, 0x0a /* Public */,
      14,    0,   90,    2, 0x0a /* Public */,
      15,    0,   91,    2, 0x0a /* Public */,
      16,    1,   92,    2, 0x0a /* Public */,
      17,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void GameScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameScreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->traitSent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->turnMade(); break;
        case 2: _t->voteMade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addCharacterToWindow((*reinterpret_cast< Character(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->changeTrait((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->sendTrait((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sendVoteMade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setTurn(); break;
        case 8: _t->enableVoteButton(); break;
        case 9: _t->changeVotes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->turnToNextScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameScreen::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScreen::traitSent)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScreen::turnMade)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameScreen::voteMade)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QStackedWidget::staticMetaObject>(),
    qt_meta_stringdata_GameScreen.data,
    qt_meta_data_GameScreen,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameScreen.stringdata0))
        return static_cast<void*>(this);
    return QStackedWidget::qt_metacast(_clname);
}

int GameScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void GameScreen::traitSent(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameScreen::turnMade()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameScreen::voteMade(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
