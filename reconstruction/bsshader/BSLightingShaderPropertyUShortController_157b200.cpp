// Source exposure: mixed (local binary analysis and community name declarations).
// Code origin: original body; scoped TLS restoration follows cookbook rule 21.
// Cookbook: 21
// 0x157b200 BSLightingShaderPropertyUShortController::LinkObject
#include "BSLightingShaderPropertyUShortController_157b200.h"

// Link under the controller allocation category, restoring it during unwind.
void BSLightingShaderPropertyUShortController::LinkObject(NiStream& stream)
{
    AllocationTagScope category(30);
    NiFloatInterpController::LinkObject(stream);
}
