// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original stand-in declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectLIGH, InitializeData, OBJ_LIGH, data, time, radius, color, flags, fallofExponent, fov, nearDistance, flickerPeriodRecip, flickerIntensityAmplitude, flickerMovementAmplitude, fade, sound, lensFlare: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00, unknown10C, unknown118: GUESS(low); inaccessible portions of the stand-in.
#pragma once

#include <cstdint>
#include <cstddef>

struct OBJ_LIGH
{
    std::int32_t time;
    std::uint32_t radius;
    std::uint32_t color;
    std::uint32_t flags;
    float fallofExponent;
    float fov;
    float nearDistance;
    float flickerPeriodRecip;
    float flickerIntensityAmplitude;
    float flickerMovementAmplitude;
};

class TESObjectLIGH
{
public:
    void InitializeData();
    std::uint8_t unknown00[0xE0];
    OBJ_LIGH data;
    float fade;
    std::uint32_t unknown10C;
    void* sound;
    std::uint8_t unknown118[0x10];
    void* lensFlare;
};
static_assert(offsetof(TESObjectLIGH, data) == 0xE0, "data offset");
static_assert(offsetof(TESObjectLIGH, lensFlare) == 0x128, "lens flare offset");
