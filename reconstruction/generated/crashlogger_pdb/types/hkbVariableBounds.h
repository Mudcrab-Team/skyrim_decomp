// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbVariableBounds; size 0x8
#pragma once

#include "hkbVariableValue.h"
struct hkbVariableBounds {
    hkbVariableValue m_min;
    hkbVariableValue m_max;
};
static_assert(sizeof(hkbVariableBounds) == 8, "hkbVariableBounds layout differs from the PDB");
