// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x78db20 TESActionData::GetSourceActorState
// 0x78db80 TESActionData::Process
// Adapted bodies: none
#include "TESActionData_78db20.h"

// ActionProcessor, Apply, g_actionProcessor: GUESS(low)
class ActionProcessor
{
public:
    void Apply(TESActionData* data);
};
extern ActionProcessor* g_actionProcessor;

ActorState* TESActionData::GetSourceActorState() const
{
    auto* reference = source;
    Actor* actor = nullptr;
    if (reference) {
        actor = static_cast<Actor*>(reference->formType == 0x3E ? reference : nullptr);
    }
    return actor ? &actor->actorState : nullptr;
}

void TESActionData::Process()
{
    return g_actionProcessor->Apply(this);
}
