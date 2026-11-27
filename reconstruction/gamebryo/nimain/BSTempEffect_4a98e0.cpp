// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation based on the pinned game build; names as labelled in the header.
// Adapted bodies: none
// 0x4a98e0 BSTempEffect::dtor
#include "BSTempEffect_4a98e0.h"

BSTempEffect::~BSTempEffect()
{
    cell = nullptr;
    lifetime = 0.0f;
    age = 0.0f;
    initialized = false;
}
