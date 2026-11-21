// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CellMopp; size 0xf0
#pragma once

#include "NiRefObject_f24a9221.h"
#include "NiTObjectArray_RE__NiPointer_RE__bhkRigidBody_e6d9eaba.h"
#include "array_RE__CellMopp__HeightFieldWeldingTasklet_4_681eb4a4.h"
struct CellMopp {
    NiRefObject_f24a9221 _base;
    void* unk10;
    array_RE__CellMopp__HeightFieldWeldingTasklet_4_681eb4a4 weldingTasklets;
    NiTObjectArray_RE__NiPointer_RE__bhkRigidBody_e6d9eaba rigidBodies;
};
static_assert(sizeof(CellMopp) == 240, "CellMopp layout differs from the PDB");
