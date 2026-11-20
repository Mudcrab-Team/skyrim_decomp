// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmesh; size 0x118
// one of 2 different PDB types sharing this name
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "BSNavmeshGrid_c9591d96.h"
#include "BSTArray_RE__BSNavmeshClosedDoorInfo_9a936848.h"
#include "BSTArray_RE__BSNavmeshCoverEdge_1fbb6b34_cd1ea944.h"
#include "BSTArray_RE__BSNavmeshEdgeExtraInfo_5cd255b2_f5884050.h"
#include "BSTArray_RE__BSNavmeshTriangleDoorPortal_fca76049.h"
#include "BSTArray_RE__BSNavmeshTriangle_cedda0c4_4bf688c1.h"
#include "BSTArray_RE__BSNavmeshVertex_12b8449c_92a99fb3.h"
#include "BSTArray_RE__NiPointer_RE__BSNavmeshObstacleUndoData_82f50b3b_95c00e96.h"
#include "BSTArray_void_9eb8914c.h"
#include "BSTSmartPointer_RE__BSPathingCell_9e2f1f4e.h"
struct BSNavmesh_vtbl;
struct RE__BSTScatterTable_RE__BSCRC32_unsigned_short_std__equal_to_unsigned_short_RE__BSTScat_4fb90e12;
struct BSNavmesh_712a9777 {
    BSNavmesh_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad00C;
    BSTArray_RE__BSNavmeshVertex_12b8449c_92a99fb3 vertices;
    BSTArray_RE__BSNavmeshTriangle_cedda0c4_4bf688c1 triangles;
    BSTArray_RE__BSNavmeshEdgeExtraInfo_5cd255b2_f5884050 extraEdgeInfo;
    BSTArray_RE__BSNavmeshTriangleDoorPortal_fca76049 doorPortals;
    BSTArray_RE__BSNavmeshClosedDoorInfo_9a936848 closedDoors;
    BSTArray_RE__BSNavmeshCoverEdge_1fbb6b34_cd1ea944 coverArray;
    BSNavmeshGrid_c9591d96 meshGrid;
    BSTArray_RE__NiPointer_RE__BSNavmeshObstacleUndoData_82f50b3b_95c00e96 obstacles;
    RE__BSTScatterTable_RE__BSCRC32_unsigned_short_std__equal_to_unsigned_short_RE__BSTScat_4fb90e12* triangleToObstacleMap;
    BSTArray_void_9eb8914c unk0F0;
    BSTSmartPointer_RE__BSPathingCell_9e2f1f4e parentCell;
    void* unk110;
};
static_assert(sizeof(BSNavmesh_712a9777) == 280, "BSNavmesh_712a9777 layout differs from the PDB");
