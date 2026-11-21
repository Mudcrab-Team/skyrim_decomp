// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingLocation; size 0x30
#pragma once

#include "BSTSmartPointer_RE__BSPathingCell_9e2f1f4e.h"
struct BSNavmeshInfo;
struct RE__BSTArray_RE__BSNavmeshInfo_0d68aa2f;
struct BSPathingLocation {
    unsigned char location_raw[16];
    BSNavmeshInfo* navMeshInfo;
    RE__BSTArray_RE__BSNavmeshInfo_0d68aa2f* navMeshInfoArray;
    BSTSmartPointer_RE__BSPathingCell_9e2f1f4e pathingCell;
    unsigned short triangle;
    unsigned char flags;
    unsigned char clientData;
    unsigned char undefined_2c[4];
};
static_assert(sizeof(BSPathingLocation) == 48, "BSPathingLocation layout differs from the PDB");
