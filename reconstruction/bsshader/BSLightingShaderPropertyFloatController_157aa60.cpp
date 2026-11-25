// Source exposure: mixed (local binary analysis and community name declarations).
// Code origin: original body; scoped TLS restoration follows cookbook rule 21.
// Cookbook: 21
// 0x157aa60 BSLightingShaderPropertyFloatController::LinkObject
#include "BSLightingShaderPropertyFloatController_157aa60.h"

// Link under the controller allocation category, restoring it during unwind.
void BSLightingShaderPropertyFloatController::LinkObject(NiStream& stream)
{
    AllocationTagScope category(30);
    NiFloatInterpController::LinkObject(stream);
}
