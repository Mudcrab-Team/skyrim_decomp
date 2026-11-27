// Source exposure: binary-analysis (names are guesses; signature read from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSGamepadDevice, BSGamepadDevice::Functioncfbcc0: GUESS(low)
#pragma once

class BSGamepadDevice
{
public:
    void Functioncfbcc0(float x, float y, float deadzone, float maxMagnitude, float* outX, float* outY);
};
