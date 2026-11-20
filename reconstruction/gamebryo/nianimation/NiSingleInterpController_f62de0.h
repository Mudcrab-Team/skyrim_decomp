// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiSingleInterpController: EXE_RTTI
// NiInterpController: STANDIN EXE_RTTI
// CopyMembers, CloneInterpolator, interpolator: GUESS(low)
#pragma once

#include "NiKeyBasedInterpolator_f6e600.h"
#include "NiTimeController_ef7ff0.h"

class NiInterpController : public NiTimeController
{
public:
    NiInterpController();
    void CopyMembers(NiInterpController* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    bool IsEqual(NiObject* object) override;
};

class NiSingleInterpController : public NiInterpController
{
public:
    void CopyMembers(NiSingleInterpController* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    bool IsEqual(NiObject* object) override;
    NiSingleInterpController();

private:
    InterpolatorKeyDataPointer<NiTimeRangeInterpolator> interpolator;
};
