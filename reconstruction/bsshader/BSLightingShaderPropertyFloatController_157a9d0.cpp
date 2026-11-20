// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original shader controller methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x157a9d0 BSLightingShaderPropertyFloatController::CopyMembers
// 0x157aa00 BSLightingShaderPropertyFloatController::LoadBinary
// 0x157aad0 BSLightingShaderPropertyFloatController::SaveBinary
// 0x157aed0 BSLightingShaderPropertyFloatController::IsValidTarget
// 0x157af20 BSLightingShaderPropertyFloatController::GetControlledValue
// Adapted bodies: none
#include "BSLightingShaderPropertyFloatController_157a9d0.h"

#include "bssystem/NiStream_19e930.h"

// NiRTTI_BSLightingShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// gLightingFloatIndices: GUESS(low)
extern const NiRTTI NiRTTI_BSLightingShaderProperty;
extern std::uint32_t gLightingFloatIndices[];

void BSLightingShaderPropertyFloatController::CopyMembers(BSLightingShaderPropertyFloatController* dest)
{
    NiFloatInterpController::CopyMembers(dest);
    dest->controlledVariable = controlledVariable;
}

void BSLightingShaderPropertyFloatController::LoadBinary(NiStream& stream)
{
    NiFloatInterpController::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(controlledVariable);
    const auto transferred = binary->_readFn(binary, &controlledVariable, sizeof(controlledVariable), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void BSLightingShaderPropertyFloatController::SaveBinary(NiStream& stream)
{
    NiFloatInterpController::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(controlledVariable);
    const auto transferred = binary->_writeFn(binary, &controlledVariable, sizeof(controlledVariable), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool BSLightingShaderPropertyFloatController::IsValidTarget(const NiObjectNET* candidate) const
{
    if (candidate) {
        for (auto* rtti = candidate->GetRTTI(); rtti; rtti = rtti->baseRTTI) {
            if (rtti == &NiRTTI_BSLightingShaderProperty) {
                return true;
            }
        }
    }
    return false;
}

void BSLightingShaderPropertyFloatController::GetControlledValue(float& value) const
{
    const auto index = gLightingFloatIndices[controlledVariable];
    const auto* shader = static_cast<const ShaderPropertyMaterialTarget*>(target);
    const auto* values = reinterpret_cast<const float*>(shader->material);
    value = values[index];
}
