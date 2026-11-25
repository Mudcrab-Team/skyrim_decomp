// Exposure detail: (pinned-image observations and public declarations).
// Source exposure: mixed
// Code origin: original hand-written reconstruction; no adapted body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSStandardSoundDef, BGSSoundOutput, BSIAttenuationCharacteristics, outputModel, attenuation, GetMaxDistance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// GetOutputMaxDistance, outputFlags, reserved: GUESS(low); behavior-derived names.
// BGSSoundOutput, BSIAttenuationCharacteristics: STANDIN OBSERVED; minimal accessed layouts.
// 0x32c260 BGSStandardSoundDef::GetOutputMaxDistance

#pragma once
#include <cstddef>
#include <cstdint>
class BSIAttenuationCharacteristics {
public:
    virtual ~BSIAttenuationCharacteristics();
    virtual float GetMaxDistance() const = 0;
};
class BGSSoundOutput {
public:
    std::uint8_t reserved[0x28];
    std::uint8_t outputFlags;
    std::uint8_t reserved29[7];
    BSIAttenuationCharacteristics* attenuation;
};
class BGSStandardSoundDef {
public:
    float GetOutputMaxDistance() const;
    std::uint8_t reserved[0x48];
    BGSSoundOutput* outputModel;
};
static_assert(offsetof(BGSSoundOutput, attenuation) == 0x30, "observed layout");
static_assert(offsetof(BGSStandardSoundDef, outputModel) == 0x48, "observed layout");
