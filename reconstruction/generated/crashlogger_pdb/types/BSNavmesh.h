// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmesh; size 0x118
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSIntrusiveRefCounted_8d4cb673.h"
#include "BSNavmeshGrid.h"
#include "BSTArray_RE__BSNavmeshClosedDoorInfo_9a936848_ede795de.h"
#include "BSTArray_RE__BSNavmeshCoverEdge_1fbb6b34.h"
#include "BSTArray_RE__BSNavmeshEdgeExtraInfo_5cd255b2.h"
#include "BSTArray_RE__BSNavmeshTriangleDoorPortal_fca76049_673e2ef9.h"
#include "BSTArray_RE__BSNavmeshTriangle_cedda0c4.h"
#include "BSTArray_RE__BSNavmeshVertex_12b8449c.h"
#include "BSTArray_RE__NiPointer_RE__BSNavmeshObstacleUndoData_82f50b3b.h"
#include "BSTArray_void_9eb8914c_e1846db0.h"
#include "BSTSmartPointer_RE__BSPathingCell_9e2f1f4e.h"
struct BSNavmesh_vtbl;
struct RE__BSTScatterTable_RE__BSCRC32_unsigned_short_std__equal_to_unsigned_short_RE__BSTScat_4fb90e12;
struct BSNavmesh {
    BSNavmesh_vtbl* __vftable;
    BSIntrusiveRefCounted_8d4cb673 _base_BSIntrusiveRefCounted;
    unsigned int pad00C;
    BSTArray_RE__BSNavmeshVertex_12b8449c vertices;
    BSTArray_RE__BSNavmeshTriangle_cedda0c4 triangles;
    BSTArray_RE__BSNavmeshEdgeExtraInfo_5cd255b2 extraEdgeInfo;
    BSTArray_RE__BSNavmeshTriangleDoorPortal_fca76049_673e2ef9 doorPortals;
    BSTArray_RE__BSNavmeshClosedDoorInfo_9a936848_ede795de closedDoors;
    BSTArray_RE__BSNavmeshCoverEdge_1fbb6b34 coverArray;
    BSNavmeshGrid meshGrid;
    BSTArray_RE__NiPointer_RE__BSNavmeshObstacleUndoData_82f50b3b obstacles;
    RE__BSTScatterTable_RE__BSCRC32_unsigned_short_std__equal_to_unsigned_short_RE__BSTScat_4fb90e12* triangleToObstacleMap;
    BSTArray_void_9eb8914c_e1846db0 unk0F0;
    BSTSmartPointer_RE__BSPathingCell_9e2f1f4e parentCell;
    void* unk110;
};
static_assert(sizeof(BSNavmesh) == 280, "BSNavmesh layout differs from the PDB");
