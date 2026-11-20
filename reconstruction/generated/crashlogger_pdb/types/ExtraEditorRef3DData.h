// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraEditorRef3DData; size 0x20
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "NiPointer_RE__BSLines_0e09ce79.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
struct ExtraEditorRef3DData {
    BSExtraData_4ca6af76 _base;
    NiPointer_RE__NiAVObject_9e3aa701 data3D;
    NiPointer_RE__BSLines_0e09ce79 dataBound;
};
static_assert(sizeof(ExtraEditorRef3DData) == 32, "ExtraEditorRef3DData layout differs from the PDB");
