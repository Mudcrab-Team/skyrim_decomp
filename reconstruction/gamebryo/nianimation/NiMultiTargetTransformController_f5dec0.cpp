// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf5dec0 NiMultiTargetTransformController::GetInterpolatorIndexFx
// 0xf5df00 NiMultiTargetTransformController::GetInterpolator
// 0xf5e260 NiMultiTargetTransformController::CreateBlendInterpolator
// 0xf5e300 NiMultiTargetTransformController::TargetIsRequiredType
// 0xf5e530 NiMultiTargetTransformController::InterpolatorIsCorrectType
#include "NiMultiTargetTransformController_f5dec0.h"

// invalidInterpolatorIndex: GUESS(low); sentinel returned when a target name is absent.
extern const std::uint16_t invalidInterpolatorIndex;

std::uint16_t NiMultiTargetTransformController::GetInterpolatorIndexFx(const BSFixedString& id) const
{
    for (std::uint16_t i = 0; i < numInterps; ++i) {
        const auto* object = targets[i];
        if (object && object->name.text == id.text) {
            return i;
        }
    }
    return invalidInterpolatorIndex;
}

NiInterpolator* NiMultiTargetTransformController::GetInterpolator(std::uint16_t index) const
{
    return &blendInterps[index];
}

NiBlendInterpolator* NiMultiTargetTransformController::CreateBlendInterpolator(std::uint16_t index, bool, bool, float, std::uint8_t) const
{
    return &blendInterps[index];
}

bool NiMultiTargetTransformController::TargetIsRequiredType() const
{
    if (target) {
        for (auto* rtti = target->GetRTTI(); rtti; rtti = rtti->baseRTTI) {
            if (rtti == &NiRTTI_NiAVObject) {
                return true;
            }
        }
    }
    return false;
}

bool NiMultiTargetTransformController::InterpolatorIsCorrectType(const TransformValueSupport* input, std::uint16_t) const
{
    return input->IsTransformValueSupported();
}
