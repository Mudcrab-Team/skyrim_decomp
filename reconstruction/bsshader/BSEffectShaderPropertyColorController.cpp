// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original body written from the local listing.
// 0x157c850 BSEffectShaderPropertyColorController::GetCtlrID
#include "BSEffectShaderPropertyColorController.h"

const char* BSEffectShaderPropertyColorController::GetCtlrID()
{
    return kEffectColorCtlrIDs[controlledVariable];
}
