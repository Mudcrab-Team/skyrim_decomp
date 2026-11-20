// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkCustomAttributes; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkCustomAttributes__Attribute;
struct hkCustomAttributes {
    hkCustomAttributes__Attribute* m_attributes_0;
    int m_numAttributes_8;
    char _pad_C[4];
};
static_assert(sizeof(hkCustomAttributes) == 16, "hkCustomAttributes layout differs from the PDB");
