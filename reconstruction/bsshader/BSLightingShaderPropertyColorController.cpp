// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original body written from the local listing.
// 0x157bb80 BSLightingShaderPropertyColorController::GetCtlrID
#include "BSLightingShaderPropertyColorController.h"

const char* BSLightingShaderPropertyColorController::GetCtlrID()
{
    return kLightingColorCtlrIDs[controlledVariable];
}
