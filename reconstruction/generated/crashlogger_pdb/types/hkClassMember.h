// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkClassMember; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkEnum_hkClassMember__Type_uint8.h"
#include "hkFlags_hkClassMember__FlagValues_uint16.h"
struct hkClass;
struct hkClassEnum;
struct hkCustomAttributes;
struct hkClassMember {
    char* m_name_0;
    hkClass* m_class_8;
    hkClassEnum* m_enum_10;
    hkEnum_hkClassMember__Type_uint8 m_type_18;
    hkEnum_hkClassMember__Type_uint8 m_subtype_19;
    short m_cArraySize_1A;
    hkFlags_hkClassMember__FlagValues_uint16 m_flags_1C;
    unsigned short m_offset_1E;
    hkCustomAttributes* m_attributes_20;
};
static_assert(sizeof(hkClassMember) == 40, "hkClassMember layout differs from the PDB");
