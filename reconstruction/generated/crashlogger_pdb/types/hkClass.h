// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkClass; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkFlags_hkClass__FlagValues_uint32.h"
struct hkClassEnum;
struct hkClassMember;
struct hkCustomAttributes;
struct hkClass {
    char* m_name_0;
    hkClass* m_parent_8;
    int m_objectSize_10;
    int m_numImplementedInterfaces_14;
    hkClassEnum* m_declaredEnums_18;
    int m_numDeclaredEnums_20;
    char _pad_24[4];
    hkClassMember* m_declaredMembers_28;
    int m_numDeclaredMembers_30;
    char _pad_34[4];
    void* m_defaults_38;
    hkCustomAttributes* m_attributes_40;
    hkFlags_hkClass__FlagValues_uint32 m_flags_48;
    int m_describedVersion_4C;
};
static_assert(sizeof(hkClass) == 80, "hkClass layout differs from the PDB");
