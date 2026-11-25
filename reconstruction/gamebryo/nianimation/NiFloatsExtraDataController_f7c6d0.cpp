// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf7c6d0 NiFloatsExtraDataController::IsEqual
#include "NiFloatsExtraDataController_f7c6d0.h"

bool NiFloatsExtraDataController::IsEqual(ControllerObject* other)
{
    if (FloatsControllerBase::IsEqual(other) &&
        index == static_cast<NiFloatsExtraDataController*>(other)->index) {
        return true;
    }
    return false;
}
