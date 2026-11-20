// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiFrustum; size 0x1c
#pragma once
struct NiFrustum {
    float fLeft;
    float fRight;
    float fTop;
    float fBottom;
    float fNear;
    float fFar;
    bool bOrtho;
    unsigned char undefined_19[3];
};
static_assert(sizeof(NiFrustum) == 28, "NiFrustum layout differs from the PDB");
