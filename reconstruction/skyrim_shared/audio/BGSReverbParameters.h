// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the form and reverb interface layouts follow the cited public declarations.
// BGSReverbParameters, BSIReverbType, InitializeData, ReverbParams, data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReverbParams::decayTime, hfReference, roomFilter, roomHFFilter, reflections, reverb: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReverbParams::decayHFRatio, reflectionDelay, reverbDelay, diffusionPct, densityPct, pad0D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DoGetRoomLevel, DoGetRoomHFLevel, DoGetDecayTime, DoGetDecayHFRatio, DoGetReflectionLevel, DoGetReflectionDelay: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DoGetReverbLevel, DoGetReverbDelay, DoGetDiffusion, DoGetDensity, DoGetHFReference: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class BSIReverbType
{
public:
    virtual std::int32_t DoGetRoomLevel() const = 0;
    virtual std::int32_t DoGetRoomHFLevel() const = 0;
    virtual float DoGetDecayTime() const = 0;
    virtual float DoGetDecayHFRatio() const = 0;
    virtual std::int32_t DoGetReflectionLevel() const = 0;
    virtual float DoGetReflectionDelay() const = 0;
    virtual std::int32_t DoGetReverbLevel() const = 0;
    virtual float DoGetReverbDelay() const = 0;
    virtual float DoGetDiffusion() const = 0;
    virtual float DoGetDensity() const = 0;
    virtual float DoGetHFReference() const = 0;
};

class BGSReverbParameters : public TESForm, public BSIReverbType
{
public:
    float DoGetReverbDelay() const override;
    void InitializeData() override;
    std::int32_t DoGetRoomLevel() const override;
    std::int32_t DoGetRoomHFLevel() const override;
    float DoGetDecayTime() const override;
    float DoGetDecayHFRatio() const override;
    std::int32_t DoGetReflectionLevel() const override;
    float DoGetReflectionDelay() const override;
    std::int32_t DoGetReverbLevel() const override;
    float DoGetDiffusion() const override;
    float DoGetDensity() const override;
    float DoGetHFReference() const override;

private:
    struct ReverbParams
    {
        std::uint16_t decayTime;
        std::uint16_t hfReference;
        std::int8_t roomFilter;
        std::int8_t roomHFFilter;
        std::int8_t reflections;
        std::int8_t reverb;
        std::uint8_t decayHFRatio;
        std::uint8_t reflectionDelay;
        std::uint8_t reverbDelay;
        std::uint8_t diffusionPct;
        std::uint8_t densityPct;
        std::uint8_t pad0D;
    } data;
    static_assert(sizeof(ReverbParams) == 0xE, "reverb parameter size");
};
static_assert(sizeof(BGSReverbParameters) == 0x38, "reverb form size");
