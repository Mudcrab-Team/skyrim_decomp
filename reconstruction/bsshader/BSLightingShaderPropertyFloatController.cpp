// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original body written from the local listing.
// 0x157b070 BSLightingShaderPropertyFloatController::GetCtlrID
#include "BSLightingShaderPropertyFloatController.h"

const char* BSLightingShaderPropertyFloatController::GetCtlrID()
{
    return kLightingFloatCtlrIDs[controlledVariable];
}
