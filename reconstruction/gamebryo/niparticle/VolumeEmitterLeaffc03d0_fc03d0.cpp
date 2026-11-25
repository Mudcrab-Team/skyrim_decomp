// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfc03d0 VolumeEmitterLeaffc03d0::IsEqual
#include "VolumeEmitterLeaffc03d0_fc03d0.h"

bool VolumeEmitterLeaffc03d0::IsEqual(EmitterObject* other)
{
    if (!EmitterBase::IsEqual(other)) {
        return false;
    }
    const auto* emitter = static_cast<VolumeEmitterLeaffc03d0*>(other);
    if (volume && !emitter->volume) {
        return false;
    }
    if (!volume && emitter->volume) {
        return false;
    }
    return true;
}
