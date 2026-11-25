// Source exposure: mixed (community headers; the pinned image listing; a permitted sibling body).
// Code origin: body adapted from a permitted sibling body, slots and offsets checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x5dbae0 ReferenceEffect::FinishLoadGame
// Adapted bodies: ReferenceEffect::FinishLoadGame
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffect.cpp:51
#include "ReferenceEffect_5dbae0.h"

// After the base load, the effect is re-initialised; age and finished state survive the reset, then it is updated once with no elapsed time.
void ReferenceEffect::FinishLoadGame(BGSLoadGameBuffer* a_buf)
{
    BSTempEffect::FinishLoadGame(a_buf);
    float savedAge = age;
    bool savedFinished = finished;
    Init();
    age = savedAge;
    finished = savedFinished;
    Update(0.0f);
}
