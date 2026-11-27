// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xf9f520 NiPSysCylinderEmitter::IsEqual
#include "NiPSysCylinderEmitter_f9f520.h"

// Compares two cylinder emitters by base state, radius, and height.
bool NiPSysCylinderEmitter::IsEqual(NiObject* a_other)
{
    if (!NiPSysVolumeEmitter::IsEqual(a_other))
    {
        return false;
    }

    const NiPSysCylinderEmitter* other = static_cast<const NiPSysCylinderEmitter*>(a_other);
    if (emitterRadius != other->emitterRadius || emitterHeight != other->emitterHeight)
    {
        return false;
    }

    return true;
}
