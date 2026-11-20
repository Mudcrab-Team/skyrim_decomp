// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ValueType
#pragma once
enum class ValueType : int {
    kUndefined = 0,
    kNull = 1,
    kBoolean = 2,
    kNumber = 3,
    kString = 4,
    kStringW = 5,
    kObject = 6,
    kArray = 7,
    kDisplayObject = 8,
    kValueMask = 15,
    kManagedBit = 64,
    kConvertBit = 128,
    kConvertBoolean = 130,
    kConvertNumber = 131,
    kConvertString = 132,
    kConvertStringW = 133,
    kTypeMask = 143,
};
