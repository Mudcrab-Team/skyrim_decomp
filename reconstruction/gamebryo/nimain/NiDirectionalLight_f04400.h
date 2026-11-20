// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiDirectionalLight: EXE_RTTI
// directionX, directionY, directionZ: GUESS(low)
// CopyMembers: GUESS(low)
#pragma once

#include "NiLight_eed1f0.h"

class NiDirectionalLight : public NiLight
{
public:
    void CopyMembers(NiDirectionalLight* dest);

private:
    float directionX;
    float directionY;
    float directionZ;
};
