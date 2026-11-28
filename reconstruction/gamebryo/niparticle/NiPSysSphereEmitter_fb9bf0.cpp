// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xfb9bf0 NiPSysSphereEmitter::IsEqual
#include "NiPSysSphereEmitter_fb9bf0.h"

// Checks base volume emitter equality and compares the sphere radius.
bool NiPSysSphereEmitter::IsEqual(NiObject* object)
{
    if (!NiPSysVolumeEmitter::IsEqual(object))
    {
        return false;
    }
    NiPSysSphereEmitter* other = static_cast<NiPSysSphereEmitter*>(object);
    if (emitterRadius != other->emitterRadius)
    {
        return false;
    }
    return true;
}
