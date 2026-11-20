// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original shader controller methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x157bc80 BSEffectShaderPropertyFloatController::CopyMembers
// 0x157bcb0 BSEffectShaderPropertyFloatController::LoadBinary
// 0x157bd80 BSEffectShaderPropertyFloatController::SaveBinary
// 0x157c0a0 BSEffectShaderPropertyFloatController::IsValidTarget
// 0x157c0f0 BSEffectShaderPropertyFloatController::GetControlledValue
// Adapted bodies: none
#include "BSEffectShaderPropertyFloatController_157bc80.h"

#include "bssystem/NiStream_19e930.h"

// NiRTTI_BSEffectShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// gEffectFloatIndices: GUESS(low)
extern const NiRTTI NiRTTI_BSEffectShaderProperty;
extern std::uint32_t gEffectFloatIndices[];

void BSEffectShaderPropertyFloatController::CopyMembers(BSEffectShaderPropertyFloatController* dest)
{
    NiFloatInterpController::CopyMembers(dest);
    dest->controlledVariable = controlledVariable;
}

void BSEffectShaderPropertyFloatController::LoadBinary(NiStream& stream)
{
    NiFloatInterpController::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(controlledVariable);
    const auto transferred = binary->_readFn(binary, &controlledVariable, sizeof(controlledVariable), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void BSEffectShaderPropertyFloatController::SaveBinary(NiStream& stream)
{
    NiFloatInterpController::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(controlledVariable);
    const auto transferred = binary->_writeFn(binary, &controlledVariable, sizeof(controlledVariable), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool BSEffectShaderPropertyFloatController::IsValidTarget(const NiObjectNET* candidate) const
{
    if (candidate) {
        for (auto* rtti = candidate->GetRTTI(); rtti; rtti = rtti->baseRTTI) {
            if (rtti == &NiRTTI_BSEffectShaderProperty) {
                return true;
            }
        }
    }
    return false;
}

void BSEffectShaderPropertyFloatController::GetControlledValue(float& value) const
{
    const auto index = gEffectFloatIndices[controlledVariable];
    const auto* shader = static_cast<const ShaderPropertyMaterialTarget*>(target);
    const auto* values = reinterpret_cast<const float*>(shader->material);
    value = values[index];
}
