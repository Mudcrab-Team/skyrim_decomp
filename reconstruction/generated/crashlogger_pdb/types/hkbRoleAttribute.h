// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbRoleAttribute; size 0x4
#pragma once

#include "enumeration_RE__hkbRoleAttribute__RoleFlags_short_0ec9ba19.h"
#include "enumeration_RE__hkbRoleAttribute__Role_short_a1292288.h"
struct hkbRoleAttribute {
    enumeration_RE__hkbRoleAttribute__Role_short_a1292288 m_role;
    enumeration_RE__hkbRoleAttribute__RoleFlags_short_0ec9ba19 m_flags;
};
static_assert(sizeof(hkbRoleAttribute) == 4, "hkbRoleAttribute layout differs from the PDB");
