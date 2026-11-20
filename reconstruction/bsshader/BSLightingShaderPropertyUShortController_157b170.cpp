// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original shader controller methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x157b170 BSLightingShaderPropertyUShortController::CopyMembers
// 0x157b1a0 BSLightingShaderPropertyUShortController::LoadBinary
// 0x157b270 BSLightingShaderPropertyUShortController::SaveBinary
// 0x157b3d0 BSLightingShaderPropertyUShortController::InitializeValueLookup
// 0x157b3f0 BSLightingShaderPropertyUShortController::IsValidTarget
// 0x157b440 BSLightingShaderPropertyUShortController::GetControlledValue
// Adapted bodies: none
#include "BSLightingShaderPropertyUShortController_157b170.h"

#include "bssystem/NiStream_19e930.h"

// NiRTTI_BSLightingShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// gLightingUShortIndices: GUESS(low)
extern const NiRTTI NiRTTI_BSLightingShaderProperty;
extern std::uint32_t gLightingUShortIndices[];

void BSLightingShaderPropertyUShortController::CopyMembers(BSLightingShaderPropertyUShortController* dest)
{
    NiFloatInterpController::CopyMembers(dest);
    dest->controlledVariable = controlledVariable;
}

void BSLightingShaderPropertyUShortController::LoadBinary(NiStream& stream)
{
    NiFloatInterpController::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(controlledVariable);
    const auto transferred = binary->_readFn(binary, &controlledVariable, sizeof(controlledVariable), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void BSLightingShaderPropertyUShortController::SaveBinary(NiStream& stream)
{
    NiFloatInterpController::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(controlledVariable);
    const auto transferred = binary->_writeFn(binary, &controlledVariable, sizeof(controlledVariable), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool BSLightingShaderPropertyUShortController::IsValidTarget(const NiObjectNET* candidate) const
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

void BSLightingShaderPropertyUShortController::GetControlledValue(float& value) const
{
    const auto index = gLightingUShortIndices[controlledVariable];
    const auto* shader = static_cast<const ShaderPropertyMaterialTarget*>(target);
    const auto* values = reinterpret_cast<const std::uint16_t*>(shader->material);
    value = static_cast<float>(values[index]);
}

void BSLightingShaderPropertyUShortController::InitializeValueLookup()
{
    gLightingUShortIndices[0] >>= 1;
    gLightingUShortIndices[1] = 0x7FFFFFFFu;
}
