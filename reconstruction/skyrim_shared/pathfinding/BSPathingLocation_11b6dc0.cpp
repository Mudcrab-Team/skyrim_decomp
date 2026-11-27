// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSPathingLocation: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPathingLocation::GetBestNavMeshInfo: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x11b6dc0 BSPathingLocation::GetBestNavMeshInfo
#include "BSPathingLocation_11b6dc0.h"

// Return the direct navmesh info, or the first array entry when flagged.
BSNavmeshInfo* BSPathingLocation::GetBestNavMeshInfo() const
{
    if (navMeshInfo) {
        return navMeshInfo;
    }
    if (navMeshInfoArray && (flags & 1u) != 0) {
        return navMeshInfoArray->data[0];
    }
    return nullptr;
}
