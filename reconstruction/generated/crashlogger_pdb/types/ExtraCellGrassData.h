// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraCellGrassData; size 0x30
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTArray_RE__CellGrassData_bca8e7ee.h"
#include "NiPointer_RE__AddCellGrassTask_1683ee60.h"
struct ExtraCellGrassData {
    BSExtraData_4ca6af76 _base;
    BSTArray_RE__CellGrassData_bca8e7ee grassHandles;
    NiPointer_RE__AddCellGrassTask_1683ee60 addGrassTask;
};
static_assert(sizeof(ExtraCellGrassData) == 48, "ExtraCellGrassData layout differs from the PDB");
