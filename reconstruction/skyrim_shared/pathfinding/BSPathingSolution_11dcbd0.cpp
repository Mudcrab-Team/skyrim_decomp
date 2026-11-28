// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0x11dcbd0 BSPathingSolution::GetLastNode
#include "BSPathingSolution_11dcbd0.h"

BSPathingNode* BSPathingSolution::GetLastNode()
{
    if (currentPathingNodes.Empty()) {
        return nullptr;
    }
    return &currentPathingNodes.Back();
}
