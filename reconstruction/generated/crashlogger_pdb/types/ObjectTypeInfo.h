// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ObjectTypeInfo; size 0x4e
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSIntrusiveRefCounted.h"
#include "BSTSmartPointer_RE__BSScript__ObjectTypeInfo_d4d9dc4f.h"
#pragma pack(push, 2)
struct ObjectTypeInfo {
    BSIntrusiveRefCounted _base;
    unsigned char undefined_4[4];
    BSFixedString_char_83b572b4 name;
    BSTSmartPointer_RE__BSScript__ObjectTypeInfo_d4d9dc4f parentTypeInfo;
    unsigned char undefined_18[8];
    unsigned int linkedValid : 2;
    unsigned int userFlagCount : 6;
    unsigned int variableCount : 10;
    unsigned int variableUserFlagCount : 6;
    unsigned int pad20_24 : 8;
    unsigned int initialValueCount : 10;
    unsigned int propertyCount : 10;
    unsigned int staticFunctionCount : 9;
    unsigned int pad24_29 : 3;
    unsigned int emptyStateMemberFunctionCount : 11;
    unsigned int namedStateCount : 7;
    unsigned int pad28_18 : 14;
    unsigned char undefined_2c[4];
    void* data;
    unsigned char undefined_38[22];
};
#pragma pack(pop)
static_assert(sizeof(ObjectTypeInfo) == 78, "ObjectTypeInfo layout differs from the PDB");
