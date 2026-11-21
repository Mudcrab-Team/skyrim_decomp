// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiUnionBV: EXE_RTTI
// Differs: GUESS(low)
#pragma once

#include "NiBoundingVolume_f25b40.h"

class NiUnionBV : public NiBoundingVolume
{
public:
    bool Differs(const NiBoundingVolume& other) const;
};
