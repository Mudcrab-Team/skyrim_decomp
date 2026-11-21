// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiGeometry; size 0x138
#pragma once

#include "NiAVObject.h"
#include "NiPointer_RE__NiGeometryData_4e1e6ea3.h"
#include "NiPointer_RE__NiProperty_f6f7b5d2.h"
#include "NiPointer_RE__NiSkinInstance_af94d754.h"
struct NiGeometry {
    NiAVObject _base;
    NiPointer_RE__NiProperty_f6f7b5d2 spPropertyState;
    NiPointer_RE__NiProperty_f6f7b5d2 spEffectState;
    NiPointer_RE__NiSkinInstance_af94d754 spSkinInstance;
    NiPointer_RE__NiGeometryData_4e1e6ea3 spModelData;
    unsigned long long unk130;
};
static_assert(sizeof(NiGeometry) == 312, "NiGeometry layout differs from the PDB");
