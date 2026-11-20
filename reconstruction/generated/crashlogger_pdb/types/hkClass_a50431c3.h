// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkClass; size 0x50
// one of 2 different PDB types sharing this name
#pragma once

#include "enumeration_RE__hkClass__FlagValues_unsigned_int_a7582133.h"
struct hkClassEnum_c1f7e791;
struct hkClassMember_722c2cb5;
struct hkCustomAttributes_7007198f;
struct hkClass_a50431c3 {
    unsigned char* name;
    hkClass_a50431c3* parent;
    int objectSize;
    int numImplementedInterfaces;
    hkClassEnum_c1f7e791* declaredEnums;
    int numDeclaredEnums;
    unsigned int pad24;
    hkClassMember_722c2cb5* declaredMembers;
    int numDeclaredMembers;
    unsigned int pad34;
    void* defaults;
    hkCustomAttributes_7007198f* attributes;
    enumeration_RE__hkClass__FlagValues_unsigned_int_a7582133 flags;
    int describedVersion;
};
static_assert(sizeof(hkClass_a50431c3) == 80, "hkClass_a50431c3 layout differs from the PDB");
