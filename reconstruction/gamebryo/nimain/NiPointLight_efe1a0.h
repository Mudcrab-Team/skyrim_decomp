// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPointLight: EXE_RTTI
// constAttenuation, linearAttenuation, quadraticAttenuation: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMembers: GUESS(low)
#pragma once

#include "NiLight_eed1f0.h"

class NiPointLight : public NiLight
{
public:
    void CopyMembers(NiPointLight* dest);

private:
    float constAttenuation;
    float linearAttenuation;
    float quadraticAttenuation;
};
