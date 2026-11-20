// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original body written from the local listing.
// 0x157b590 BSLightingShaderPropertyUShortController::GetCtlrID
#include "BSLightingShaderPropertyUShortController.h"

const char* BSLightingShaderPropertyUShortController::GetCtlrID()
{
    return kLightingUShortCtlrIDs[controlledVariable];
}
