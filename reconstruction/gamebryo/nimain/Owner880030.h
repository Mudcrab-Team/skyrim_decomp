// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image. Stamped as a twin of matched 0xf2dae0 (gamebryo/nimain/NiBoxBV_f2dae0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BoxShape: GUESS(low)
// Function880030, Owner880030: GUESS(low) STANDIN
// box, SaveBinary, IsSameVolume, Differs: GUESS(low) STANDIN
#pragma once
#include "NiBoxBV_f2dae0.h"

class Owner880030 : public NiBoundingVolume
{
public:
    void Function880030(NiStream& stream);
    void SaveBinary(NiStream& stream);
    bool IsSameVolume(const NiBoundingVolume& other) const;
    bool Differs(const NiBoundingVolume& other) const;

private:
    BoxShape box;
};
