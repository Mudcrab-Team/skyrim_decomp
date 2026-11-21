// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkClassMember; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "enumeration_RE__hkClassMember__FlagValues_unsigned_short_61713249.h"
#include "enumeration_RE__hkClassMember__Type_unsigned_char_64da1c03.h"
struct hkClassEnum_c1f7e791;
struct hkClass_a50431c3;
struct hkCustomAttributes_7007198f;
struct hkClassMember_722c2cb5 {
    unsigned char* m_name;
    hkClass_a50431c3* m_class;
    hkClassEnum_c1f7e791* m_enum;
    enumeration_RE__hkClassMember__Type_unsigned_char_64da1c03 m_type;
    enumeration_RE__hkClassMember__Type_unsigned_char_64da1c03 m_subtype;
    short m_cArraySize;
    enumeration_RE__hkClassMember__FlagValues_unsigned_short_61713249 m_flags;
    unsigned short m_offset;
    hkCustomAttributes_7007198f* m_attributes;
};
static_assert(sizeof(hkClassMember_722c2cb5) == 40, "hkClassMember_722c2cb5 layout differs from the PDB");
