// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code. Stamped as a twin of matched 0xf62e60 (gamebryo/nianimation/NiSingleInterpController_f62de0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfbf040 Ownerfbf040::LoadBinary
#include "Ownerfbf040.h"

// guess: same compiled code as matched 0xf62e60 apart from relocated fields; its role here is not established.
void Ownerfbf040::LoadBinary(NiStream& stream)
{
    NiInterpController::LoadBinary(stream);
    interpolator.Reset(static_cast<NiTimeRangeInterpolator*>(ReadStreamObjectLink(stream)));
}

Ownerfbf040::Ownerfbf040()
{

}
