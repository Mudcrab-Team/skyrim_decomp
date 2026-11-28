// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xfbb220 NiPSysTurbulenceFieldModifier::IsEqual
#include "NiPSysTurbulenceFieldModifier_fbb220.h"

// Compare base field modifier state and the turbulence frequency parameter for equality.
bool NiPSysTurbulenceFieldModifier::IsEqual(NiObject* a_other)
{
    if (!NiPSysFieldModifier::IsEqual(a_other)) {
        return false;
    }

    NiPSysTurbulenceFieldModifier* other = static_cast<NiPSysTurbulenceFieldModifier*>(a_other);
    return other->frequency == frequency;
}
