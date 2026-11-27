// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSPathingLocation: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPathingLocation::QValid: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x11b7d40 BSPathingLocation::QValid
#include "BSPathingLocation_11b7d40.h"

// Return whether the location is marked valid or its pathing cell reports valid.
bool BSPathingLocation::QValid() const
{
    if ((flags & 2u) > 0) {
        return true;
    }
    if (pathingCell && pathingCell->Unk_07()) {
        return true;
    }
    return false;
}
