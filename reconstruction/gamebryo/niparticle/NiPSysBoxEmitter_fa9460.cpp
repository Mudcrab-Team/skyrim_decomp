// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xfa9460 NiPSysBoxEmitter::IsEqual
#include "NiPSysBoxEmitter_fa9460.h"

// Compares two box emitters by base state and box dimensions.
bool NiPSysBoxEmitter::IsEqual(NiObject* a_other)
{
    if (!NiPSysVolumeEmitter::IsEqual(a_other))
    {
        return false;
    }

    const NiPSysBoxEmitter* other = static_cast<const NiPSysBoxEmitter*>(a_other);
    if (emitterWidth != other->emitterWidth ||
        emitterHeight != other->emitterHeight ||
        emitterDepth != other->emitterDepth)
    {
        return false;
    }

    return true;
}
