// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpMoppCode; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "CodeInfo.h"
#include "hkArray_unsigned_char_c72971e9.h"
#include "hkReferencedObject.h"
struct hkpMoppCode {
    hkReferencedObject _base;
    CodeInfo info;
    hkArray_unsigned_char_c72971e9 data;
    unsigned char buildType;  // BuildType in the PDB is wider than this slot
    unsigned char pad31;
    unsigned short pad32;
    unsigned int pad34;
    unsigned long long pad38;
};
static_assert(sizeof(hkpMoppCode) == 64, "hkpMoppCode layout differs from the PDB");
