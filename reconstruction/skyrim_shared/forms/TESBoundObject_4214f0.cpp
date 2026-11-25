// Source exposure: mixed (community names; pinned-image observations).
// Code origin: original; observed setting selection and float arithmetic
// SPDX-License-Identifier: CC0-1.0
// 0x4214f0 TESBoundObject::GetTemperedValue
// Adapted bodies: none
#include "TESBoundObject_4214f0.h"

float TESBoundObject::GetTemperedValue(float value, float health)
{
    float maximum;
    if (temperScalingEnabled && temperScalingSetting)
        maximum = temperScalingSetting->value;
    else
        maximum = temperBaseline;
    float result;
    if (maximum > temperBaseline) {
        result = health - temperBaseline;
        maximum -= temperBaseline;
        result /= maximum;
        result += temperBaseline;
        result *= value;
    } else {
        result = value;
    }
    return result;
}
