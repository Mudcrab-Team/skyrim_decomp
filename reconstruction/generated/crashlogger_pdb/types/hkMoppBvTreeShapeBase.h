// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMoppBvTreeShapeBase; size 0x50
#pragma once

#include "hkVector4.h"
#include "hkpBvTreeShape_f0c78d2e.h"
struct hkpMoppCode;
struct hkMoppBvTreeShapeBase {
    hkpBvTreeShape_f0c78d2e _base;
    hkpMoppCode* code;
    unsigned char* moppData;
    unsigned int moppDataSize;
    unsigned int pad3C;
    hkVector4 codeInfoCopy;
};
static_assert(sizeof(hkMoppBvTreeShapeBase) == 80, "hkMoppBvTreeShapeBase layout differs from the PDB");
