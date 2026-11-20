// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original shader controller methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x157c340 BSEffectShaderPropertyColorController::CopyMembers
// 0x157c370 BSEffectShaderPropertyColorController::LoadBinary
// 0x157c3f0 BSEffectShaderPropertyColorController::SaveBinary
// 0x157c690 BSEffectShaderPropertyColorController::InitializeValueLookup
// 0x157c6b0 BSEffectShaderPropertyColorController::IsValidTarget
// 0x157c700 BSEffectShaderPropertyColorController::GetControlledValue
// Adapted bodies: none
#include "BSEffectShaderPropertyColorController_157c340.h"

#include "bssystem/NiStream_19e930.h"

// NiRTTI_BSEffectShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// gEffectColorOffsets: GUESS(low)
extern const NiRTTI NiRTTI_BSEffectShaderProperty;
extern std::uint32_t gEffectColorOffsets[];

void BSEffectShaderPropertyColorController::CopyMembers(BSEffectShaderPropertyColorController* dest)
{
    NiPoint3InterpController::CopyMembers(dest);
    dest->controlledVariable = controlledVariable;
}

void BSEffectShaderPropertyColorController::LoadBinary(NiStream& stream)
{
    NiPoint3InterpController::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(controlledVariable);
    const auto transferred = binary->_readFn(binary, &controlledVariable, sizeof(controlledVariable), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void BSEffectShaderPropertyColorController::SaveBinary(NiStream& stream)
{
    NiPoint3InterpController::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(controlledVariable);
    const auto transferred = binary->_writeFn(binary, &controlledVariable, sizeof(controlledVariable), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool BSEffectShaderPropertyColorController::IsValidTarget(const NiObjectNET* candidate) const
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

void BSEffectShaderPropertyColorController::GetControlledValue(ShaderControllerColor& value) const
{
    const auto offset = gEffectColorOffsets[controlledVariable];
    const auto* storage = reinterpret_cast<const std::uint8_t*>(target);
    const auto* color = reinterpret_cast<const ShaderControllerColor*>(storage + offset);
    value.red = color->red;
    value.green = color->green;
    value.blue = color->blue;
}

void BSEffectShaderPropertyColorController::InitializeValueLookup()
{
    gEffectColorOffsets[0] = 0xFFFFFFFFu;
}
