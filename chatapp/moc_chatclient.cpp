/****************************************************************************
** Meta object code from reading C++ file 'chatclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "chatclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatClient_t {
    QByteArrayData data[25];
    char stringdata0[357];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatClient_t qt_meta_stringdata_ChatClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChatClient"
QT_MOC_LITERAL(1, 11, 12), // "loginSuccess"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "loginFailed"
QT_MOC_LITERAL(4, 37, 7), // "message"
QT_MOC_LITERAL(5, 45, 15), // "messageReceived"
QT_MOC_LITERAL(6, 61, 8), // "roomName"
QT_MOC_LITERAL(7, 70, 8), // "username"
QT_MOC_LITERAL(8, 79, 19), // "onlineUsersReceived"
QT_MOC_LITERAL(9, 99, 5), // "users"
QT_MOC_LITERAL(10, 105, 17), // "roomUsersReceived"
QT_MOC_LITERAL(11, 123, 21), // "onlineFriendsReceived"
QT_MOC_LITERAL(12, 145, 22), // "friendRequestsReceived"
QT_MOC_LITERAL(13, 168, 19), // "friendsListReceived"
QT_MOC_LITERAL(14, 188, 17), // "userRoomsReceived"
QT_MOC_LITERAL(15, 206, 5), // "rooms"
QT_MOC_LITERAL(16, 212, 18), // "inviteRoomReceived"
QT_MOC_LITERAL(17, 231, 10), // "senderName"
QT_MOC_LITERAL(18, 242, 13), // "actionSuccess"
QT_MOC_LITERAL(19, 256, 12), // "actionFailed"
QT_MOC_LITERAL(20, 269, 17), // "beRemovedFromRoom"
QT_MOC_LITERAL(21, 287, 20), // "inviteChat11Received"
QT_MOC_LITERAL(22, 308, 24), // "disconnectChat11Received"
QT_MOC_LITERAL(23, 333, 11), // "onConnected"
QT_MOC_LITERAL(24, 345, 11) // "onReadyRead"

    },
    "ChatClient\0loginSuccess\0\0loginFailed\0"
    "message\0messageReceived\0roomName\0"
    "username\0onlineUsersReceived\0users\0"
    "roomUsersReceived\0onlineFriendsReceived\0"
    "friendRequestsReceived\0friendsListReceived\0"
    "userRoomsReceived\0rooms\0inviteRoomReceived\0"
    "senderName\0actionSuccess\0actionFailed\0"
    "beRemovedFromRoom\0inviteChat11Received\0"
    "disconnectChat11Received\0onConnected\0"
    "onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    1,  100,    2, 0x06 /* Public */,
       5,    3,  103,    2, 0x06 /* Public */,
       8,    1,  110,    2, 0x06 /* Public */,
      10,    1,  113,    2, 0x06 /* Public */,
      11,    1,  116,    2, 0x06 /* Public */,
      12,    1,  119,    2, 0x06 /* Public */,
      13,    1,  122,    2, 0x06 /* Public */,
      14,    1,  125,    2, 0x06 /* Public */,
      16,    2,  128,    2, 0x06 /* Public */,
      18,    1,  133,    2, 0x06 /* Public */,
      19,    1,  136,    2, 0x06 /* Public */,
      20,    0,  139,    2, 0x06 /* Public */,
      21,    1,  140,    2, 0x06 /* Public */,
      22,    1,  143,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,  146,    2, 0x08 /* Private */,
      24,    0,  147,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    4,
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,    6,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChatClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loginSuccess(); break;
        case 1: _t->loginFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->onlineUsersReceived((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 4: _t->roomUsersReceived((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 5: _t->onlineFriendsReceived((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 6: _t->friendRequestsReceived((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 7: _t->friendsListReceived((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 8: _t->userRoomsReceived((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 9: _t->inviteRoomReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 10: _t->actionSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->actionFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->beRemovedFromRoom(); break;
        case 13: _t->inviteChat11Received((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->disconnectChat11Received((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->onConnected(); break;
        case 16: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChatClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::loginSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::loginFailed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::messageReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::onlineUsersReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::roomUsersReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::onlineFriendsReceived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::friendRequestsReceived)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::friendsListReceived)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::userRoomsReceived)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::inviteRoomReceived)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::actionSuccess)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::actionFailed)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::beRemovedFromRoom)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::inviteChat11Received)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::disconnectChat11Received)) {
                *result = 14;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ChatClient.data,
    qt_meta_data_ChatClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ChatClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ChatClient::loginSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ChatClient::loginFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChatClient::messageReceived(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChatClient::onlineUsersReceived(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ChatClient::roomUsersReceived(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ChatClient::onlineFriendsReceived(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ChatClient::friendRequestsReceived(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ChatClient::friendsListReceived(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ChatClient::userRoomsReceived(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ChatClient::inviteRoomReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ChatClient::actionSuccess(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ChatClient::actionFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ChatClient::beRemovedFromRoom()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void ChatClient::inviteChat11Received(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ChatClient::disconnectChat11Received(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
