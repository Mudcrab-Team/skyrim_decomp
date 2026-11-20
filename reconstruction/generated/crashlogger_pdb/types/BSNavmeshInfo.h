// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshInfo; size 0x48
#pragma once

#include "BSTSmartPointer_RE__BSPathingCell_9e2f1f4e.h"
#include "NiPoint3.h"
struct BSCompressedNavmeshBounds;
struct BSNavmesh_712a9777;
struct BSTSmartPointer_RE__BSPathingDoor_281903e3;
struct BSNavmeshInfo {
    unsigned int navMeshID;
    NiPoint3 approxLocation;
    BSTSmartPointer_RE__BSPathingDoor_281903e3* connectedDoorsArray;
    unsigned int* adjacentMeshesArray;
    unsigned short connectedDoorCount;
    unsigned short adjacentMeshCount;
    float preferredPercent;
    BSNavmesh_712a9777* navMesh;
    BSCompressedNavmeshBounds* bounds;
    BSTSmartPointer_RE__BSPathingCell_9e2f1f4e pathingCell;
    unsigned short preferredStartIndex;
    unsigned char uiFlags;
    unsigned char undefined_43[5];
};
static_assert(sizeof(BSNavmeshInfo) == 72, "BSNavmeshInfo layout differs from the PDB");
