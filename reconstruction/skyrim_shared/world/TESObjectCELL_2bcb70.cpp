// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Cookbook: 0x2bcb70 34
// 0x2bcb70 TESObjectCELL::GetFogPower
// Adapted bodies: none
#include "TESObjectCELL_2bcb70.h"

// Return the fog power for an interior cell, delegating to its lighting template when inherited.
float TESObjectCELL::GetFogPower() const
{
    float result = 1.0f;
    if ((cellFlags & 1) != 0 && interiorData) {
        if ((interiorData->lightingTemplateInheritanceFlags & 1) != 0 && lightingTemplate) {
            return lightingTemplate->GetFogPower();
        }
        result = interiorData->fogPower;
    }
    return result;
}
