// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xfa4df0 NiPSysAirFieldModifier::IsEqual
#include "NiPSysAirFieldModifier_fa4df0.h"

// Compare base field modifier state and the three air-field float parameters for equality.
bool NiPSysAirFieldModifier::IsEqual(NiObject* a_other)
{
    if (!NiPSysFieldModifier::IsEqual(a_other)) {
        return false;
    }

    NiPSysAirFieldModifier* other = static_cast<NiPSysAirFieldModifier*>(a_other);
    return other->unk60 == unk60 &&
           other->unk64 == unk64 &&
           other->unk68 == unk68;
}
