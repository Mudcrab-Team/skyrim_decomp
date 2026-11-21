// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbVariableInfo; size 0x6
#pragma once

#include "hkbRoleAttribute.h"
struct hkbVariableInfo {
    hkbRoleAttribute m_role;
    unsigned char m_type_raw[2];
};
static_assert(sizeof(hkbVariableInfo) == 6, "hkbVariableInfo layout differs from the PDB");
