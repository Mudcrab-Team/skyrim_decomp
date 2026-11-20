// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// Adapted bodies: reverb accessors and defaults follow the earlier BGSReverbParameters unit and CommonLibSSE-NG@b93280e include/RE/B/BGSReverbParameters.h:55 (MIT).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// 0x328bf0 BGSReverbParameters::InitializeData
// 0x328e60 BGSReverbParameters::DoGetRoomLevel
// 0x328e70 BGSReverbParameters::DoGetRoomHFLevel
// 0x328e80 BGSReverbParameters::DoGetDecayTime
// 0x328ea0 BGSReverbParameters::DoGetDecayHFRatio
// 0x328ec0 BGSReverbParameters::DoGetReflectionLevel
// 0x328ed0 BGSReverbParameters::DoGetReflectionDelay
// 0x328ef0 BGSReverbParameters::DoGetReverbLevel
// 0x328f20 BGSReverbParameters::DoGetDiffusion
// 0x328f40 BGSReverbParameters::DoGetDensity
// 0x328f60 BGSReverbParameters::DoGetHFReference
#include "BGSReverbParameters.h"

// decayTimeScale, decayHFRatioScale, reflectionDelayScale: GUESS(low)
extern const float decayTimeScale;
extern const float decayHFRatioScale;
extern const float reflectionDelayScale;

void BGSReverbParameters::InitializeData()
{
    data.decayTime = 1250;
    data.hfReference = 800;
    data.roomFilter = 100;
    data.roomHFFilter = 100;
    data.reflections = 0;
    data.reverb = 0;
    data.decayHFRatio = 100;
    data.reflectionDelay = 0;
    data.reverbDelay = 0;
    data.diffusionPct = 100;
}

std::int32_t BGSReverbParameters::DoGetRoomLevel() const
{
    return data.roomFilter * 100;
}

std::int32_t BGSReverbParameters::DoGetRoomHFLevel() const
{
    return data.roomHFFilter * 100;
}

float BGSReverbParameters::DoGetDecayTime() const
{
    return static_cast<float>(data.decayTime) * decayTimeScale;
}

float BGSReverbParameters::DoGetDecayHFRatio() const
{
    return static_cast<float>(data.decayHFRatio) * decayHFRatioScale;
}

std::int32_t BGSReverbParameters::DoGetReflectionLevel() const
{
    return data.reflections * 100;
}

float BGSReverbParameters::DoGetReflectionDelay() const
{
    return static_cast<float>(data.reflectionDelay) * reflectionDelayScale;
}

std::int32_t BGSReverbParameters::DoGetReverbLevel() const
{
    return data.reverb * 100;
}

float BGSReverbParameters::DoGetDiffusion() const
{
    return static_cast<float>(data.diffusionPct);
}

float BGSReverbParameters::DoGetDensity() const
{
    return static_cast<float>(data.densityPct);
}

float BGSReverbParameters::DoGetHFReference() const
{
    return static_cast<float>(data.hfReference);
}
