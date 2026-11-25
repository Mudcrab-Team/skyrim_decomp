// Near miss: 12.0 alignment distance | register-schedule
// Code origin: original reconstruction; declaration names from labelled sources.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSGamepadDevice, ProcessRawInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0xcfbb90 BSGamepadDevice::ProcessRawInput
#include "include/cfbb90/BSGamepadDevice_cfbb90.h"

void BSGamepadDevice::ProcessRawInput(int rawX, int rawY, float& outX, float& outY)
{
    float x = static_cast<float>(rawX) * rawInputScale;
    x = x > minimumInput ? x : minimumInput;
    outX = x < maximumInput ? x : maximumInput;
    float y = static_cast<float>(rawY) * rawInputScale;
    y = y > minimumInput ? y : minimumInput;
    outY = y < maximumInput ? y : maximumInput;
}
