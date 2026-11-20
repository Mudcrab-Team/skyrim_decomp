// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Object; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSTSmartPointer_RE__BSScript__ObjectTypeInfo_d4d9dc4f.h"
struct Object_c951326f {
    unsigned int constructed : 1;
    unsigned int initialized : 1;
    unsigned int valid : 1;
    unsigned int remainingPropsToInit : 29;
    unsigned char undefined_4[4];
    BSTSmartPointer_RE__BSScript__ObjectTypeInfo_d4d9dc4f type;
    BSFixedString_char_83b572b4 currentState;
    void* lockStructure;
    unsigned long long handle;
    int refCountAndHandleLock;
    unsigned int pad2C;
};
static_assert(sizeof(Object_c951326f) == 48, "Object_c951326f layout differs from the PDB");
