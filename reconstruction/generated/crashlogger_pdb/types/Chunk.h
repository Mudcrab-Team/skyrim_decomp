// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Chunk; size 0x60
#pragma once

#include "hkArray_unsigned_short_437647d0.h"
#include "hkVector4.h"
struct Chunk {
    hkVector4 offset;
    hkArray_unsigned_short_437647d0 vertices;
    hkArray_unsigned_short_437647d0 indices;
    hkArray_unsigned_short_437647d0 stripLengths;
    hkArray_unsigned_short_437647d0 weldingInfo;
    unsigned int materialInfo;
    unsigned short reference;
    unsigned short transformIndex;
    unsigned long long pad58;
};
static_assert(sizeof(Chunk) == 96, "Chunk layout differs from the PDB");
