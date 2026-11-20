// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NavMesh; size 0x140
#pragma once

#include "BSNavmeshGrid.h"
#include "BSTArray_BSNavmeshClosedDoorInfo_cbb9d112.h"
#include "BSTArray_BSNavmeshCoverEdge_75fe60a8.h"
#include "BSTArray_BSNavmeshEdgeExtraInfo_80571277.h"
#include "BSTArray_BSNavmeshTriangleDoorPortal_4c775b06.h"
#include "BSTArray_BSNavmeshTriangle_d998cd07.h"
#include "BSTArray_BSNavmeshVertex_b859940c.h"
#include "BSTArray_NiPointer_BSNavmeshObstacleUndoData_7580917e.h"
#include "BSTSmartPointer_BSPathingCell_77af80c1.h"
#include "TESFileContainer_70f0bdf4.h"
struct BSNavmesh__VFTable;
struct BSTHashMap_uint16_NiPointer_BSNavmeshObstacleData;
struct NavMesh__VFTable;
struct TESChildCell__VFTable;
struct NavMesh {
    NavMesh__VFTable* vftable_NavMesh_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESChildCell__VFTable* vftable_TESChildCell_20;
    BSNavmesh__VFTable* vftable_BSNavmesh_28;
    int refCount_30;
    char _pad_34[4];
    BSTArray_BSNavmeshVertex_b859940c Vertices_38;
    BSTArray_BSNavmeshTriangle_d998cd07 Triangles_50;
    BSTArray_BSNavmeshEdgeExtraInfo_80571277 ExtraEdgeInfo_68;
    BSTArray_BSNavmeshTriangleDoorPortal_4c775b06 DoorPortals_80;
    BSTArray_BSNavmeshClosedDoorInfo_cbb9d112 ClosedDoors_98;
    BSTArray_BSNavmeshCoverEdge_75fe60a8 CoverArray_B0;
    BSNavmeshGrid MeshGrid_C8;
    BSTArray_NiPointer_BSNavmeshObstacleUndoData_7580917e Obstacles_F8;
    BSTHashMap_uint16_NiPointer_BSNavmeshObstacleData* TriangleToObstacleMap_110;
    char _pad_118[24];
    BSTSmartPointer_BSPathingCell_77af80c1 ParentCell_130;
    char _pad_138[8];
};
static_assert(sizeof(NavMesh) == 320, "NavMesh layout differs from the PDB");
