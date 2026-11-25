// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code. Stamped as a twin of matched 0xf62e60 (gamebryo/nianimation/NiSingleInterpController_f62de0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Ownerfbf040: GUESS(low) STANDIN
// NiInterpController, CopyMembers, interpolator: GUESS(low) STANDIN
#pragma once
#include "NiSingleInterpController_f62de0.h"

class Ownerfbf040 : public NiInterpController
{
public:
    void CopyMembers(Ownerfbf040* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    bool IsEqual(NiObject* object) override;
    Ownerfbf040();

private:
    InterpolatorKeyDataPointer<NiTimeRangeInterpolator> interpolator;
};
