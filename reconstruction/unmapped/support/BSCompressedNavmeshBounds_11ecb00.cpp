// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSCompressedNavmeshBounds: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x11ecb00 BSCompressedNavmeshBounds::BSCompressedNavmeshBounds
// CI hash: 0x11ecb00 ??0BSCompressedNavmeshBounds@@QEAA@XZ
#include "BSCompressedNavmeshBounds_11ecb00.h"

// Initializes compressed navmesh bounds to the zero point and cleared metadata.
BSCompressedNavmeshBounds::BSCompressedNavmeshBounds()
    : minBound(gZeroPoint3)
    , maxBound(gZeroPoint3)
    , unk18(0)
    , unk20(0)
    , unk28(0)
{
}
