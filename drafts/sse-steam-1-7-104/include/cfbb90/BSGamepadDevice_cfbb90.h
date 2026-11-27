// Code origin: original reconstruction; declaration names from labelled sources.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSGamepadDevice, ProcessRawInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// rawInputScale, minimumInput, maximumInput: GUESS(low); private constant roles
// 0xcfbb90 BSGamepadDevice::ProcessRawInput

#pragma once
class BSGamepadDevice {
public:
    void ProcessRawInput(int rawX, int rawY, float& outX, float& outY);
    static const float rawInputScale;
    static const float minimumInput;
    static const float maximumInput;
};
