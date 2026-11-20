// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiLookAtController: EXE_RTTI
// lookAtFlags, lookAt: GUESS(low)
#pragma once

#include "NiTimeController_ef7ff0.h"

class NiLookAtController : public NiTimeController
{
public:
    bool IsEqual(NiObject* object) override;

private:
    std::uint16_t lookAtFlags;
    NiObject* lookAt;
};
