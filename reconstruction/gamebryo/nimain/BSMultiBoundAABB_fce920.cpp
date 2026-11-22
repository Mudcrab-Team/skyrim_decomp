// Code origin: GetLength, SetCenter and RegisterStreamables are original reconstructions from local listings; other project bodies are retained.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xfce920 BSMultiBoundAABB::IsEqual
#include "BSMultiBoundAABB_fce920.h"

// IsEqual: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
static bool PointsEqual(const NiPoint3& a_lhs, const NiPoint3& a_rhs)
{
    return a_lhs.x == a_rhs.x && a_lhs.y == a_rhs.y && a_lhs.z == a_rhs.z;
}

bool BSMultiBoundAABB::IsEqual(NiObject* a_object)
{
    bool equal = IsEqualBase(this, a_object);
    if (equal) {
        auto other = static_cast<BSMultiBoundAABB*>(a_object);
        equal = PointsEqual(unk1C, other->unk1C);
        equal &= PointsEqual(unk2C, other->unk2C);
    }
    return equal;
}
