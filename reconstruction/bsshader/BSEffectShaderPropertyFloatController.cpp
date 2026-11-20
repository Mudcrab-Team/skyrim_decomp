// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original body written from the local listing.
// 0x157c240 BSEffectShaderPropertyFloatController::GetCtlrID
#include "BSEffectShaderPropertyFloatController.h"

const char* BSEffectShaderPropertyFloatController::GetCtlrID()
{
    return kEffectFloatCtlrIDs[controlledVariable];
}
