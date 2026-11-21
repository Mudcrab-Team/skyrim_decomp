// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiLight: EXE_RTTI
// unknown110, CopyMembers: GUESS(low)
// NiLight::~NiLight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiAVObject.h"

class NiLight : public NiAVObject
{
public:
    void CopyMembers(NiLight* dest);
    ~NiLight() override;

private:
    std::uint8_t unknown110[0x30];
};
