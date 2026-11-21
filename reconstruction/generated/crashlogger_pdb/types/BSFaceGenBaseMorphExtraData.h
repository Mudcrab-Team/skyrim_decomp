// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenBaseMorphExtraData; size 0x28
#pragma once

#include "BSFixedString_char_83b572b4.h"
struct NiPoint3;
struct BSFaceGenBaseMorphExtraData {
    char32_t* vftable_BSFaceGenBaseMorphExtraData_0;
    unsigned char _pad_8;
    unsigned char _pad_0[7];
    BSFixedString_char_83b572b4 Name_10;
    NiPoint3* vertexData;
    unsigned int modelVertexCount;
    unsigned int vertexCount;
};
static_assert(sizeof(BSFaceGenBaseMorphExtraData) == 40, "BSFaceGenBaseMorphExtraData layout differs from the PDB");
