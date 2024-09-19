/****************************************************************************
** Meta object code from reading C++ file 'batteryinfomodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/batteryinfomodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'batteryinfomodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBatteryInfoModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSBatteryInfoModelENDCLASS = QtMocHelpers::stringData(
    "BatteryInfoModel",
    "voltageChanged",
    "",
    "voltage",
    "chargeLevelChanged",
    "chargeLevel",
    "designMaxCapacityChanged",
    "capacity",
    "powerModeChanged",
    "PowerMode",
    "mode",
    "dischargeTimeChanged",
    "time",
    "currentMaxCapacityChanged",
    "batteryTypeChanged",
    "BatteryType",
    "type",
    "batteryHealthChanged",
    "BatteryHealth",
    "health",
    "remainingBatteryLifetimeChanged",
    "lifetime",
    "powerSupplyTypeChanged",
    "PowerSupplyType"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBatteryInfoModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       6,    1,   80,    2, 0x06,    5 /* Public */,
       8,    1,   83,    2, 0x06,    7 /* Public */,
      11,    1,   86,    2, 0x06,    9 /* Public */,
      13,    1,   89,    2, 0x06,   11 /* Public */,
      14,    1,   92,    2, 0x06,   13 /* Public */,
      17,    1,   95,    2, 0x06,   15 /* Public */,
      20,    1,   98,    2, 0x06,   17 /* Public */,
      22,    1,  101,    2, 0x06,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QTime,   12,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QTime,   21,
    QMetaType::Void, 0x80000000 | 23,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject BatteryInfoModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSBatteryInfoModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBatteryInfoModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBatteryInfoModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BatteryInfoModel, std::true_type>,
        // method 'voltageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'chargeLevelChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'designMaxCapacityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'powerModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PowerMode, std::false_type>,
        // method 'dischargeTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTime &, std::false_type>,
        // method 'currentMaxCapacityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'batteryTypeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<BatteryType, std::false_type>,
        // method 'batteryHealthChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<BatteryHealth, std::false_type>,
        // method 'remainingBatteryLifetimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTime &, std::false_type>,
        // method 'powerSupplyTypeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PowerSupplyType, std::false_type>
    >,
    nullptr
} };

void BatteryInfoModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BatteryInfoModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->voltageChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->chargeLevelChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->designMaxCapacityChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->powerModeChanged((*reinterpret_cast< std::add_pointer_t<PowerMode>>(_a[1]))); break;
        case 4: _t->dischargeTimeChanged((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 5: _t->currentMaxCapacityChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->batteryTypeChanged((*reinterpret_cast< std::add_pointer_t<BatteryType>>(_a[1]))); break;
        case 7: _t->batteryHealthChanged((*reinterpret_cast< std::add_pointer_t<BatteryHealth>>(_a[1]))); break;
        case 8: _t->remainingBatteryLifetimeChanged((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 9: _t->powerSupplyTypeChanged((*reinterpret_cast< std::add_pointer_t<PowerSupplyType>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BatteryInfoModel::*)(double );
            if (_t _q_method = &BatteryInfoModel::voltageChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BatteryInfoModel::*)(int );
            if (_t _q_method = &BatteryInfoModel::chargeLevelChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BatteryInfoModel::*)(double );
            if (_t _q_method = &BatteryInfoModel::designMaxCapacityChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BatteryInfoModel::*)(PowerMode );
            if (_t _q_method = &BatteryInfoModel::powerModeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BatteryInfoModel::*)(const QTime & );
            if (_t _q_method = &BatteryInfoModel::dischargeTimeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BatteryInfoModel::*)(double );
            if (_t _q_method = &BatteryInfoModel::currentMaxCapacityChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (BatteryInfoModel::*)(BatteryType );
            if (_t _q_method = &BatteryInfoModel::batteryTypeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (BatteryInfoModel::*)(BatteryHealth );
            if (_t _q_method = &BatteryInfoModel::batteryHealthChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (BatteryInfoModel::*)(const QTime & );
            if (_t _q_method = &BatteryInfoModel::remainingBatteryLifetimeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (BatteryInfoModel::*)(PowerSupplyType );
            if (_t _q_method = &BatteryInfoModel::powerSupplyTypeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject *BatteryInfoModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BatteryInfoModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBatteryInfoModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BatteryInfoModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void BatteryInfoModel::voltageChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BatteryInfoModel::chargeLevelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BatteryInfoModel::designMaxCapacityChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BatteryInfoModel::powerModeChanged(PowerMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BatteryInfoModel::dischargeTimeChanged(const QTime & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BatteryInfoModel::currentMaxCapacityChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BatteryInfoModel::batteryTypeChanged(BatteryType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void BatteryInfoModel::batteryHealthChanged(BatteryHealth _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void BatteryInfoModel::remainingBatteryLifetimeChanged(const QTime & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void BatteryInfoModel::powerSupplyTypeChanged(PowerSupplyType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
