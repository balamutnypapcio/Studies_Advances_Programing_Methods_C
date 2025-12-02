/****************************************************************************
** Meta object code from reading C++ file 'camera.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../libQGLViewer/QGLViewer/camera.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_qglviewer__Camera_t {
    uint offsetsAndSizes[168];
    char stringdata0[18];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[4];
    char stringdata5[15];
    char stringdata6[11];
    char stringdata7[2];
    char stringdata8[6];
    char stringdata9[4];
    char stringdata10[12];
    char stringdata11[3];
    char stringdata12[7];
    char stringdata13[17];
    char stringdata14[10];
    char stringdata15[7];
    char stringdata16[7];
    char stringdata17[16];
    char stringdata18[10];
    char stringdata19[7];
    char stringdata20[7];
    char stringdata21[15];
    char stringdata22[4];
    char stringdata23[4];
    char stringdata24[16];
    char stringdata25[10];
    char stringdata26[12];
    char stringdata27[25];
    char stringdata28[6];
    char stringdata29[22];
    char stringdata30[14];
    char stringdata31[6];
    char stringdata32[3];
    char stringdata33[9];
    char stringdata34[8];
    char stringdata35[5];
    char stringdata36[5];
    char stringdata37[15];
    char stringdata38[4];
    char stringdata39[25];
    char stringdata40[5];
    char stringdata41[17];
    char stringdata42[15];
    char stringdata43[7];
    char stringdata44[24];
    char stringdata45[6];
    char stringdata46[7];
    char stringdata47[20];
    char stringdata48[6];
    char stringdata49[20];
    char stringdata50[5];
    char stringdata51[24];
    char stringdata52[15];
    char stringdata53[15];
    char stringdata54[24];
    char stringdata55[20];
    char stringdata56[14];
    char stringdata57[6];
    char stringdata58[23];
    char stringdata59[22];
    char stringdata60[31];
    char stringdata61[9];
    char stringdata62[24];
    char stringdata63[4];
    char stringdata64[24];
    char stringdata65[2];
    char stringdata66[22];
    char stringdata67[4];
    char stringdata68[18];
    char stringdata69[9];
    char stringdata70[11];
    char stringdata71[10];
    char stringdata72[13];
    char stringdata73[12];
    char stringdata74[6];
    char stringdata75[14];
    char stringdata76[9];
    char stringdata77[28];
    char stringdata78[23];
    char stringdata79[17];
    char stringdata80[19];
    char stringdata81[12];
    char stringdata82[8];
    char stringdata83[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_qglviewer__Camera_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_qglviewer__Camera_t qt_meta_stringdata_qglviewer__Camera = {
    {
        QT_MOC_LITERAL(0, 17),  // "qglviewer::Camera"
        QT_MOC_LITERAL(18, 11),  // "setPosition"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 3),  // "Vec"
        QT_MOC_LITERAL(35, 3),  // "pos"
        QT_MOC_LITERAL(39, 14),  // "setOrientation"
        QT_MOC_LITERAL(54, 10),  // "Quaternion"
        QT_MOC_LITERAL(65, 1),  // "q"
        QT_MOC_LITERAL(67, 5),  // "theta"
        QT_MOC_LITERAL(73, 3),  // "phi"
        QT_MOC_LITERAL(77, 11),  // "setUpVector"
        QT_MOC_LITERAL(89, 2),  // "up"
        QT_MOC_LITERAL(92, 6),  // "noMove"
        QT_MOC_LITERAL(99, 16),  // "setViewDirection"
        QT_MOC_LITERAL(116, 9),  // "direction"
        QT_MOC_LITERAL(126, 6),  // "lookAt"
        QT_MOC_LITERAL(133, 6),  // "target"
        QT_MOC_LITERAL(140, 15),  // "showEntireScene"
        QT_MOC_LITERAL(156, 9),  // "fitSphere"
        QT_MOC_LITERAL(166, 6),  // "center"
        QT_MOC_LITERAL(173, 6),  // "radius"
        QT_MOC_LITERAL(180, 14),  // "fitBoundingBox"
        QT_MOC_LITERAL(195, 3),  // "min"
        QT_MOC_LITERAL(199, 3),  // "max"
        QT_MOC_LITERAL(203, 15),  // "fitScreenRegion"
        QT_MOC_LITERAL(219, 9),  // "rectangle"
        QT_MOC_LITERAL(229, 11),  // "centerScene"
        QT_MOC_LITERAL(241, 24),  // "interpolateToZoomOnPixel"
        QT_MOC_LITERAL(266, 5),  // "pixel"
        QT_MOC_LITERAL(272, 21),  // "interpolateToFitScene"
        QT_MOC_LITERAL(294, 13),  // "interpolateTo"
        QT_MOC_LITERAL(308, 5),  // "Frame"
        QT_MOC_LITERAL(314, 2),  // "fr"
        QT_MOC_LITERAL(317, 8),  // "duration"
        QT_MOC_LITERAL(326, 7),  // "setType"
        QT_MOC_LITERAL(334, 4),  // "Type"
        QT_MOC_LITERAL(339, 4),  // "type"
        QT_MOC_LITERAL(344, 14),  // "setFieldOfView"
        QT_MOC_LITERAL(359, 3),  // "fov"
        QT_MOC_LITERAL(363, 24),  // "setHorizontalFieldOfView"
        QT_MOC_LITERAL(388, 4),  // "hfov"
        QT_MOC_LITERAL(393, 16),  // "setFOVToFitScene"
        QT_MOC_LITERAL(410, 14),  // "setAspectRatio"
        QT_MOC_LITERAL(425, 6),  // "aspect"
        QT_MOC_LITERAL(432, 23),  // "setScreenWidthAndHeight"
        QT_MOC_LITERAL(456, 5),  // "width"
        QT_MOC_LITERAL(462, 6),  // "height"
        QT_MOC_LITERAL(469, 19),  // "setDevicePixelRatio"
        QT_MOC_LITERAL(489, 5),  // "ratio"
        QT_MOC_LITERAL(495, 19),  // "setZNearCoefficient"
        QT_MOC_LITERAL(515, 4),  // "coef"
        QT_MOC_LITERAL(520, 23),  // "setZClippingCoefficient"
        QT_MOC_LITERAL(544, 14),  // "setSceneRadius"
        QT_MOC_LITERAL(559, 14),  // "setSceneCenter"
        QT_MOC_LITERAL(574, 23),  // "setSceneCenterFromPixel"
        QT_MOC_LITERAL(598, 19),  // "setSceneBoundingBox"
        QT_MOC_LITERAL(618, 13),  // "setPivotPoint"
        QT_MOC_LITERAL(632, 5),  // "point"
        QT_MOC_LITERAL(638, 22),  // "setPivotPointFromPixel"
        QT_MOC_LITERAL(661, 21),  // "setRevolveAroundPoint"
        QT_MOC_LITERAL(683, 30),  // "setRevolveAroundPointFromPixel"
        QT_MOC_LITERAL(714, 8),  // "setFrame"
        QT_MOC_LITERAL(723, 23),  // "ManipulatedCameraFrame*"
        QT_MOC_LITERAL(747, 3),  // "mcf"
        QT_MOC_LITERAL(751, 23),  // "setKeyFrameInterpolator"
        QT_MOC_LITERAL(775, 1),  // "i"
        QT_MOC_LITERAL(777, 21),  // "KeyFrameInterpolator*"
        QT_MOC_LITERAL(799, 3),  // "kfi"
        QT_MOC_LITERAL(803, 17),  // "addKeyFrameToPath"
        QT_MOC_LITERAL(821, 8),  // "playPath"
        QT_MOC_LITERAL(830, 10),  // "deletePath"
        QT_MOC_LITERAL(841, 9),  // "resetPath"
        QT_MOC_LITERAL(851, 12),  // "drawAllPaths"
        QT_MOC_LITERAL(864, 11),  // "setFlySpeed"
        QT_MOC_LITERAL(876, 5),  // "speed"
        QT_MOC_LITERAL(882, 13),  // "setIODistance"
        QT_MOC_LITERAL(896, 8),  // "distance"
        QT_MOC_LITERAL(905, 27),  // "setPhysicalDistanceToScreen"
        QT_MOC_LITERAL(933, 22),  // "setPhysicalScreenWidth"
        QT_MOC_LITERAL(956, 16),  // "setFocusDistance"
        QT_MOC_LITERAL(973, 18),  // "initFromDOMElement"
        QT_MOC_LITERAL(992, 11),  // "QDomElement"
        QT_MOC_LITERAL(1004, 7),  // "element"
        QT_MOC_LITERAL(1012, 15)   // "onFrameModified"
    },
    "qglviewer::Camera",
    "setPosition",
    "",
    "Vec",
    "pos",
    "setOrientation",
    "Quaternion",
    "q",
    "theta",
    "phi",
    "setUpVector",
    "up",
    "noMove",
    "setViewDirection",
    "direction",
    "lookAt",
    "target",
    "showEntireScene",
    "fitSphere",
    "center",
    "radius",
    "fitBoundingBox",
    "min",
    "max",
    "fitScreenRegion",
    "rectangle",
    "centerScene",
    "interpolateToZoomOnPixel",
    "pixel",
    "interpolateToFitScene",
    "interpolateTo",
    "Frame",
    "fr",
    "duration",
    "setType",
    "Type",
    "type",
    "setFieldOfView",
    "fov",
    "setHorizontalFieldOfView",
    "hfov",
    "setFOVToFitScene",
    "setAspectRatio",
    "aspect",
    "setScreenWidthAndHeight",
    "width",
    "height",
    "setDevicePixelRatio",
    "ratio",
    "setZNearCoefficient",
    "coef",
    "setZClippingCoefficient",
    "setSceneRadius",
    "setSceneCenter",
    "setSceneCenterFromPixel",
    "setSceneBoundingBox",
    "setPivotPoint",
    "point",
    "setPivotPointFromPixel",
    "setRevolveAroundPoint",
    "setRevolveAroundPointFromPixel",
    "setFrame",
    "ManipulatedCameraFrame*",
    "mcf",
    "setKeyFrameInterpolator",
    "i",
    "KeyFrameInterpolator*",
    "kfi",
    "addKeyFrameToPath",
    "playPath",
    "deletePath",
    "resetPath",
    "drawAllPaths",
    "setFlySpeed",
    "speed",
    "setIODistance",
    "distance",
    "setPhysicalDistanceToScreen",
    "setPhysicalScreenWidth",
    "setFocusDistance",
    "initFromDOMElement",
    "QDomElement",
    "element",
    "onFrameModified"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_qglviewer__Camera[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  290,    2, 0x0a,    1 /* Public */,
       5,    1,  293,    2, 0x0a,    3 /* Public */,
       5,    2,  296,    2, 0x0a,    5 /* Public */,
      10,    2,  301,    2, 0x0a,    8 /* Public */,
      10,    1,  306,    2, 0x2a,   11 /* Public | MethodCloned */,
      13,    1,  309,    2, 0x0a,   13 /* Public */,
      15,    1,  312,    2, 0x0a,   15 /* Public */,
      17,    0,  315,    2, 0x0a,   17 /* Public */,
      18,    2,  316,    2, 0x0a,   18 /* Public */,
      21,    2,  321,    2, 0x0a,   21 /* Public */,
      24,    1,  326,    2, 0x0a,   24 /* Public */,
      26,    0,  329,    2, 0x0a,   26 /* Public */,
      27,    1,  330,    2, 0x0a,   27 /* Public */,
      29,    0,  333,    2, 0x0a,   29 /* Public */,
      30,    2,  334,    2, 0x0a,   30 /* Public */,
      34,    1,  339,    2, 0x0a,   33 /* Public */,
      37,    1,  342,    2, 0x0a,   35 /* Public */,
      39,    1,  345,    2, 0x0a,   37 /* Public */,
      41,    0,  348,    2, 0x0a,   39 /* Public */,
      42,    1,  349,    2, 0x0a,   40 /* Public */,
      44,    2,  352,    2, 0x0a,   42 /* Public */,
      47,    1,  357,    2, 0x0a,   45 /* Public */,
      49,    1,  360,    2, 0x0a,   47 /* Public */,
      51,    1,  363,    2, 0x0a,   49 /* Public */,
      52,    1,  366,    2, 0x0a,   51 /* Public */,
      53,    1,  369,    2, 0x0a,   53 /* Public */,
      54,    1,  372,    2, 0x0a,   55 /* Public */,
      55,    2,  375,    2, 0x0a,   57 /* Public */,
      56,    1,  380,    2, 0x0a,   60 /* Public */,
      58,    1,  383,    2, 0x0a,   62 /* Public */,
      59,    1,  386,    2, 0x0a,   64 /* Public */,
      60,    1,  389,    2, 0x0a,   66 /* Public */,
      61,    1,  392,    2, 0x0a,   68 /* Public */,
      64,    2,  395,    2, 0x0a,   70 /* Public */,
      68,    1,  400,    2, 0x0a,   73 /* Public */,
      69,    1,  403,    2, 0x0a,   75 /* Public */,
      70,    1,  406,    2, 0x0a,   77 /* Public */,
      71,    1,  409,    2, 0x0a,   79 /* Public */,
      72,    0,  412,    2, 0x0a,   81 /* Public */,
      73,    1,  413,    2, 0x0a,   82 /* Public */,
      75,    1,  416,    2, 0x0a,   84 /* Public */,
      77,    1,  419,    2, 0x0a,   86 /* Public */,
      78,    1,  422,    2, 0x0a,   88 /* Public */,
      79,    1,  425,    2, 0x0a,   90 /* Public */,
      80,    1,  428,    2, 0x0a,   92 /* Public */,
      83,    0,  431,    2, 0x08,   94 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    8,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,   11,   12,
    QMetaType::Void, 0x80000000 | 3,   11,
    QMetaType::Void, 0x80000000 | 3,   14,
    QMetaType::Void, 0x80000000 | 3,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QReal,   19,   20,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   22,   23,
    QMetaType::Void, QMetaType::QRect,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   28,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31, QMetaType::QReal,   32,   33,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, QMetaType::QReal,   38,
    QMetaType::Void, QMetaType::QReal,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   46,
    QMetaType::Void, QMetaType::QReal,   48,
    QMetaType::Void, QMetaType::QReal,   50,
    QMetaType::Void, QMetaType::QReal,   50,
    QMetaType::Void, QMetaType::QReal,   20,
    QMetaType::Void, 0x80000000 | 3,   19,
    QMetaType::Bool, QMetaType::QPoint,   28,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   22,   23,
    QMetaType::Void, 0x80000000 | 3,   57,
    QMetaType::Bool, QMetaType::QPoint,   28,
    QMetaType::Void, 0x80000000 | 3,   57,
    QMetaType::Bool, QMetaType::QPoint,   28,
    QMetaType::Void, 0x80000000 | 62,   63,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 66,   65,   67,
    QMetaType::Void, QMetaType::UInt,   65,
    QMetaType::Void, QMetaType::UInt,   65,
    QMetaType::Void, QMetaType::UInt,   65,
    QMetaType::Void, QMetaType::UInt,   65,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   74,
    QMetaType::Void, QMetaType::QReal,   76,
    QMetaType::Void, QMetaType::QReal,   76,
    QMetaType::Void, QMetaType::QReal,   45,
    QMetaType::Void, QMetaType::QReal,   76,
    QMetaType::Void, 0x80000000 | 81,   82,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject qglviewer::Camera::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qglviewer__Camera.offsetsAndSizes,
    qt_meta_data_qglviewer__Camera,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_qglviewer__Camera_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Camera, std::true_type>,
        // method 'setPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setOrientation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Quaternion &, std::false_type>,
        // method 'setOrientation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setUpVector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setUpVector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setViewDirection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'lookAt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'showEntireScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fitSphere'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'fitBoundingBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'fitScreenRegion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRect &, std::false_type>,
        // method 'centerScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'interpolateToZoomOnPixel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'interpolateToFitScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'interpolateTo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Frame &, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Type, std::false_type>,
        // method 'setFieldOfView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setHorizontalFieldOfView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setFOVToFitScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setAspectRatio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setScreenWidthAndHeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setDevicePixelRatio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setZNearCoefficient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setZClippingCoefficient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setSceneRadius'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setSceneCenter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setSceneCenterFromPixel'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'setSceneBoundingBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setPivotPoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setPivotPointFromPixel'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'setRevolveAroundPoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Vec &, std::false_type>,
        // method 'setRevolveAroundPointFromPixel'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'setFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ManipulatedCameraFrame * const, std::false_type>,
        // method 'setKeyFrameInterpolator'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        QtPrivate::TypeAndForceComplete<KeyFrameInterpolator * const, std::false_type>,
        // method 'addKeyFrameToPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'playPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'deletePath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'resetPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'drawAllPaths'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setFlySpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setIODistance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setPhysicalDistanceToScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setPhysicalScreenWidth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setFocusDistance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'initFromDOMElement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDomElement &, std::false_type>,
        // method 'onFrameModified'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void qglviewer::Camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Camera *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setPosition((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 1: _t->setOrientation((*reinterpret_cast< std::add_pointer_t<Quaternion>>(_a[1]))); break;
        case 2: _t->setOrientation((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 3: _t->setUpVector((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 4: _t->setUpVector((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 5: _t->setViewDirection((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 6: _t->lookAt((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 7: _t->showEntireScene(); break;
        case 8: _t->fitSphere((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 9: _t->fitBoundingBox((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Vec>>(_a[2]))); break;
        case 10: _t->fitScreenRegion((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 11: _t->centerScene(); break;
        case 12: _t->interpolateToZoomOnPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 13: _t->interpolateToFitScene(); break;
        case 14: _t->interpolateTo((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 15: _t->setType((*reinterpret_cast< std::add_pointer_t<Type>>(_a[1]))); break;
        case 16: _t->setFieldOfView((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 17: _t->setHorizontalFieldOfView((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 18: _t->setFOVToFitScene(); break;
        case 19: _t->setAspectRatio((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 20: _t->setScreenWidthAndHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 21: _t->setDevicePixelRatio((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 22: _t->setZNearCoefficient((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 23: _t->setZClippingCoefficient((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 24: _t->setSceneRadius((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 25: _t->setSceneCenter((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 26: { bool _r = _t->setSceneCenterFromPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->setSceneBoundingBox((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Vec>>(_a[2]))); break;
        case 28: _t->setPivotPoint((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 29: { bool _r = _t->setPivotPointFromPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->setRevolveAroundPoint((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 31: { bool _r = _t->setRevolveAroundPointFromPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 32: _t->setFrame((*reinterpret_cast< std::add_pointer_t<ManipulatedCameraFrame*>>(_a[1]))); break;
        case 33: _t->setKeyFrameInterpolator((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<KeyFrameInterpolator*>>(_a[2]))); break;
        case 34: _t->addKeyFrameToPath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 35: _t->playPath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 36: _t->deletePath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 37: _t->resetPath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 38: _t->drawAllPaths(); break;
        case 39: _t->setFlySpeed((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 40: _t->setIODistance((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 41: _t->setPhysicalDistanceToScreen((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 42: _t->setPhysicalScreenWidth((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 43: _t->setFocusDistance((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 44: _t->initFromDOMElement((*reinterpret_cast< std::add_pointer_t<QDomElement>>(_a[1]))); break;
        case 45: _t->onFrameModified(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< KeyFrameInterpolator* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *qglviewer::Camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qglviewer::Camera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qglviewer__Camera.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qglviewer::Camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
