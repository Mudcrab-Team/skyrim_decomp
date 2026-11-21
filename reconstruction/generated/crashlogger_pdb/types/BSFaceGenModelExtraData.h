// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenModelExtraData; size 0x60
#pragma once

#include "NiExtraData_b2385dce.h"
struct BSFaceGenModel;
struct BSFaceGenModelExtraData {
    NiExtraData_b2385dce _base;
    BSFaceGenModel* m_model;
    unsigned char bones_raw[64];
};
static_assert(sizeof(BSFaceGenModelExtraData) == 96, "BSFaceGenModelExtraData layout differs from the PDB");
