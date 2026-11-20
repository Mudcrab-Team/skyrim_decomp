// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxValue; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "ValueType.h"
#include "ValueUnion.h"
struct ObjectInterface;
struct GFxValue {
    ObjectInterface* _objectInterface;
    ValueType _type;
    unsigned int _pad0C;
    ValueUnion _value;
};
static_assert(sizeof(GFxValue) == 24, "GFxValue layout differs from the PDB");
