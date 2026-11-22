// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// Code origin: original reconstruction from the local listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xff1770 BSBound::CopyMembers
// 0xff1870 BSBound::IsEqual
#include "BSBound_ff1770.h"

// CopyMembers: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
void BSBound::CopyMembers(BSBound* a_dest, NiCloningProcess& a_cloning)
{
    NiExtraData_CopyMembers(this, a_dest, a_cloning);
    a_dest->loaderA.x = loaderA.x;
    a_dest->loaderA.y = loaderA.y;
    a_dest->loaderA.z = loaderA.z;
    a_dest->loaderB.x = loaderB.x;
    a_dest->loaderB.y = loaderB.y;
    a_dest->loaderB.z = loaderB.z;
}

// PointsEqual: GUESS(low); stands in for the engine's NiPoint3 equality
static bool PointsEqual(const BSBoundLoader& a_lhs, const BSBoundLoader& a_rhs)
{
    return a_lhs.x == a_rhs.x && a_lhs.y == a_rhs.y && a_lhs.z == a_rhs.z;
}

// IsEqual: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
bool BSBound::IsEqual(NiObject* a_object)
{
    bool equal = NiExtraData::IsEqual(a_object);
    if (equal) {
        auto other = static_cast<BSBound*>(a_object);
        equal = PointsEqual(loaderA, other->loaderA);
        equal &= PointsEqual(loaderB, other->loaderB);
    }
    return equal;
}
