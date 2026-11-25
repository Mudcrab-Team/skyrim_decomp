// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from local target observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiControllerSequence, NiControllerSequence::InterpArrayItem, NiControllerSequence::InterpArrayItem::interpolator, NiControllerSequence::InterpArrayItem::interpCtlr: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiControllerSequence::InterpArrayItem::RegisterStreamables: GUESS(medium); inferred helper dispatches both retained streamable objects.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
#pragma once
#include "declarations/NiObject.h"

class NiControllerSequence
{
public:
    struct InterpArrayItem
    {
        NiObject* interpolator;
        NiObject* interpCtlr;
        void RegisterStreamables(NiStream& stream);
    };
};
