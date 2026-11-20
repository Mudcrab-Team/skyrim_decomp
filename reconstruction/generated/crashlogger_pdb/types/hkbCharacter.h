// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbCharacter; size 0xa0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_RE__hkbCharacter_603a2548.h"
struct hkbCharacter__VFTable;
#pragma pack(push, 4)
struct hkbCharacter {
    hkbCharacter__VFTable* vftable_hkbCharacter_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    hkArray_RE__hkbCharacter_603a2548 nearbyCharacters;
    unsigned char undefined_1c[132];
};
#pragma pack(pop)
static_assert(sizeof(hkbCharacter) == 160, "hkbCharacter layout differs from the PDB");
