// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original shader controller methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x157b690 BSLightingShaderPropertyColorController::CopyMembers
// 0x157b6c0 BSLightingShaderPropertyColorController::LoadBinary
// 0x157b740 BSLightingShaderPropertyColorController::SaveBinary
// 0x157b9c0 BSLightingShaderPropertyColorController::InitializeValueLookup
// 0x157b9e0 BSLightingShaderPropertyColorController::IsValidTarget
// 0x157ba30 BSLightingShaderPropertyColorController::GetControlledValue
// Adapted bodies: none
#include "BSLightingShaderPropertyColorController_157b690.h"

#include "bssystem/NiStream_19e930.h"

// NiRTTI_BSLightingShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// gLightingColorOffsets: GUESS(low)
extern const NiRTTI NiRTTI_BSLightingShaderProperty;
extern std::uint32_t gLightingColorOffsets[];

void BSLightingShaderPropertyColorController::CopyMembers(BSLightingShaderPropertyColorController* dest)
{
    NiPoint3InterpController::CopyMembers(dest);
    dest->controlledVariable = controlledVariable;
}

void BSLightingShaderPropertyColorController::LoadBinary(NiStream& stream)
{
    NiPoint3InterpController::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(controlledVariable);
    const auto transferred = binary->_readFn(binary, &controlledVariable, sizeof(controlledVariable), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void BSLightingShaderPropertyColorController::SaveBinary(NiStream& stream)
{
    NiPoint3InterpController::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(controlledVariable);
    const auto transferred = binary->_writeFn(binary, &controlledVariable, sizeof(controlledVariable), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool BSLightingShaderPropertyColorController::IsValidTarget(const NiObjectNET* candidate) const
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

void BSLightingShaderPropertyColorController::GetControlledValue(ShaderControllerColor& value) const
{
    const auto offset = gLightingColorOffsets[controlledVariable];
    const auto* storage = static_cast<const ShaderPropertyMaterialTarget*>(target)->material;
    const auto* color = reinterpret_cast<const ShaderControllerColor*>(storage + offset);
    value.red = color->red;
    value.green = color->green;
    value.blue = color->blue;
}

void BSLightingShaderPropertyColorController::InitializeValueLookup()
{
    gLightingColorOffsets[0] = 0x38;
    gLightingColorOffsets[1] = 0xFFFFFFFFu;
}
