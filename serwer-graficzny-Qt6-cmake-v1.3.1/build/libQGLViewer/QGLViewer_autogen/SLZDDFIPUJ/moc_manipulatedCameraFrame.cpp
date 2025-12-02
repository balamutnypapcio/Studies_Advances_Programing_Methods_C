/****************************************************************************
** Meta object code from reading C++ file 'manipulatedCameraFrame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../libQGLViewer/QGLViewer/manipulatedCameraFrame.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manipulatedCameraFrame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_qglviewer__ManipulatedCameraFrame_t {
    uint offsetsAndSizes[24];
    char stringdata0[34];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[17];
    char stringdata5[4];
    char stringdata6[3];
    char stringdata7[5];
    char stringdata8[19];
    char stringdata9[12];
    char stringdata10[8];
    char stringdata11[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_qglviewer__ManipulatedCameraFrame_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_qglviewer__ManipulatedCameraFrame_t qt_meta_stringdata_qglviewer__ManipulatedCameraFrame = {
    {
        QT_MOC_LITERAL(0, 33),  // "qglviewer::ManipulatedCameraF..."
        QT_MOC_LITERAL(34, 11),  // "setFlySpeed"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 5),  // "speed"
        QT_MOC_LITERAL(53, 16),  // "setSceneUpVector"
        QT_MOC_LITERAL(70, 3),  // "Vec"
        QT_MOC_LITERAL(74, 2),  // "up"
        QT_MOC_LITERAL(77, 4),  // "spin"
        QT_MOC_LITERAL(82, 18),  // "initFromDOMElement"
        QT_MOC_LITERAL(101, 11),  // "QDomElement"
        QT_MOC_LITERAL(113, 7),  // "element"
        QT_MOC_LITERAL(121, 9)   // "flyUpdate"
    },
    "qglviewer::ManipulatedCameraFrame",
    "setFlySpeed",
    "",
    "speed",
    "setSceneUpVector",
    "Vec",
    "up",
    "spin",
    "initFromDOMElement",
    "QDomElement",
    "element",
    "flyUpdate"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_qglviewer__ManipulatedCameraFrame[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       4,    1,   47,    2, 0x0a,    3 /* Public */,
       7,    0,   50,    2, 0x09,    5 /* Protected */,
       8,    1,   51,    2, 0x0a,    6 /* Public */,
      11,    0,   54,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject qglviewer::ManipulatedCameraFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<ManipulatedFrame::staticMetaObject>(),
    qt_meta_stringdata_qglviewer__ManipulatedCameraFrame.offsetsAndSizes,
    qt_meta_data_qglviewer__ManipulatedCameraFrame,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_qglviewer__ManipulatedCameraFrame_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ManipulatedCameraFrame, std::true_type>,
        // method 'setFlySpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setSceneUpVector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'spin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initFromDOMElement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDomElement &, std::false_type>,
        // method 'flyUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void qglviewer::ManipulatedCameraFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManipulatedCameraFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setFlySpeed((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 1: _t->setSceneUpVector((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 2: _t->spin(); break;
        case 3: _t->initFromDOMElement((*reinterpret_cast< std::add_pointer_t<QDomElement>>(_a[1]))); break;
        case 4: _t->flyUpdate(); break;
        default: ;
        }
    }
}

const QMetaObject *qglviewer::ManipulatedCameraFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qglviewer::ManipulatedCameraFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qglviewer__ManipulatedCameraFrame.stringdata0))
        return static_cast<void*>(this);
    return ManipulatedFrame::qt_metacast(_clname);
}

int qglviewer::ManipulatedCameraFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ManipulatedFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
