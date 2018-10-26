/****************************************************************************
** Meta object code from reading C++ file 'my_scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../my_scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyScene_t {
    QByteArrayData data[20];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyScene_t qt_meta_stringdata_MyScene = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyScene"
QT_MOC_LITERAL(1, 8, 23), // "sigCurrentObjectChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 2), // "co"
QT_MOC_LITERAL(4, 36, 21), // "sigDisplayModeChanged"
QT_MOC_LITERAL(5, 58, 2), // "dm"
QT_MOC_LITERAL(6, 61, 16), // "sigRadiusChanged"
QT_MOC_LITERAL(7, 78, 6), // "radius"
QT_MOC_LITERAL(8, 85, 19), // "sigWireframeChanged"
QT_MOC_LITERAL(9, 105, 2), // "on"
QT_MOC_LITERAL(10, 108, 16), // "sigSmoothChanged"
QT_MOC_LITERAL(11, 125, 24), // "sigDisplayNormalsChanged"
QT_MOC_LITERAL(12, 150, 21), // "sigFlipNormalsChanged"
QT_MOC_LITERAL(13, 172, 20), // "slotSetCurrentObject"
QT_MOC_LITERAL(14, 193, 18), // "slotSetDisplayMode"
QT_MOC_LITERAL(15, 212, 13), // "slotSetRadius"
QT_MOC_LITERAL(16, 226, 16), // "slotSetWireframe"
QT_MOC_LITERAL(17, 243, 13), // "slotSetSmooth"
QT_MOC_LITERAL(18, 257, 21), // "slotSetDisplayNormals"
QT_MOC_LITERAL(19, 279, 18) // "slotSetFlipNormals"

    },
    "MyScene\0sigCurrentObjectChanged\0\0co\0"
    "sigDisplayModeChanged\0dm\0sigRadiusChanged\0"
    "radius\0sigWireframeChanged\0on\0"
    "sigSmoothChanged\0sigDisplayNormalsChanged\0"
    "sigFlipNormalsChanged\0slotSetCurrentObject\0"
    "slotSetDisplayMode\0slotSetRadius\0"
    "slotSetWireframe\0slotSetSmooth\0"
    "slotSetDisplayNormals\0slotSetFlipNormals"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,
       8,    1,   93,    2, 0x06 /* Public */,
      10,    1,   96,    2, 0x06 /* Public */,
      11,    1,   99,    2, 0x06 /* Public */,
      12,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  105,    2, 0x0a /* Public */,
      14,    1,  108,    2, 0x0a /* Public */,
      15,    1,  111,    2, 0x0a /* Public */,
      16,    1,  114,    2, 0x0a /* Public */,
      17,    1,  117,    2, 0x0a /* Public */,
      18,    1,  120,    2, 0x0a /* Public */,
      19,    1,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void MyScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyScene *_t = static_cast<MyScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigCurrentObjectChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sigDisplayModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigRadiusChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->sigWireframeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->sigSmoothChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->sigDisplayNormalsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->sigFlipNormalsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->slotSetCurrentObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotSetDisplayMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slotSetRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->slotSetWireframe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->slotSetSmooth((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->slotSetDisplayNormals((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->slotSetFlipNormals((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MyScene::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyScene::sigCurrentObjectChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyScene::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyScene::sigDisplayModeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyScene::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyScene::sigRadiusChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyScene::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyScene::sigWireframeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyScene::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyScene::sigSmoothChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MyScene::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyScene::sigDisplayNormalsChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MyScene::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyScene::sigFlipNormalsChanged)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject MyScene::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyScene.data,
      qt_meta_data_MyScene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyScene.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MyScene::sigCurrentObjectChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyScene::sigDisplayModeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyScene::sigRadiusChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyScene::sigWireframeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyScene::sigSmoothChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyScene::sigDisplayNormalsChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyScene::sigFlipNormalsChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
