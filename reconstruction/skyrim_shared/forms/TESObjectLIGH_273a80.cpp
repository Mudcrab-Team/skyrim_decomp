// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten light defaults.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x273a80 TESObjectLIGH::InitializeData
// Adapted bodies: none.
#include "TESObjectLIGH_273a80.h"
#include <cstring>

void TESObjectLIGH::InitializeData()
{
    sound = nullptr;
    std::memset(&data, 0, sizeof(data));
    data.nearDistance = 0.001f;
    fade = 1.0f;
    data.fov = 90.0f;
    lensFlare = nullptr;
}
