// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Array; size 0x18
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "TypeInfo.h"
struct Array {
    BSIntrusiveRefCounted _base;
    unsigned int _pad04;
    TypeInfo _elementType;
    unsigned int _size;
    unsigned int _pad14;
};
static_assert(sizeof(Array) == 24, "Array layout differs from the PDB");
