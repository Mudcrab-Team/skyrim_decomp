// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSOcclusionShape; size 0x48
#pragma once

#include "NiMatrix3.h"
#include "NiObject_de5bc370.h"
#include "NiPoint3.h"
struct BSOcclusionShape {
    NiObject_de5bc370 _base;
    NiPoint3 translation;
    NiMatrix3 rotation;
    unsigned int visibilityState;
    bool updateFacesOrVertices;
    unsigned char undefined_45[3];
};
static_assert(sizeof(BSOcclusionShape) == 72, "BSOcclusionShape layout differs from the PDB");
