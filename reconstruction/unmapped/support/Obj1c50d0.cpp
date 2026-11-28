// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1c50d0 Obj1c50d0::SortRaceArray
// Adapted bodies: none.
#include "Obj1c50d0.h"

// PDB: the CrashLogger PDB name is (anonymous namespace)::SortRaceArray; the stand-in name here is kept.
// Compares two race entries case-insensitively by display name, returning -1, 0, or 1.
std::int32_t Obj1c50d0::SortRaceArray(const Race1c50d0* a_lhs, const Race1c50d0* a_rhs)
{
    const char* rhsName = a_rhs->fullName20.GetName();
    const char* lhsName = a_lhs->fullName20.GetName();
    int cmp = _stricmp(lhsName, rhsName);
    if (cmp > 0) {
        return 1;
    }
    return (cmp < 0) ? -1 : 0;
}
