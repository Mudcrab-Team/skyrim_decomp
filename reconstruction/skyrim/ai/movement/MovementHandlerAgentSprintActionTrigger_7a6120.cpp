// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x7a6120 MovementHandlerAgentSprintActionTrigger::SaveGame
// Adapted bodies: MovementHandlerAgentSprintActionTrigger::SaveGame from the sibling source named in the header
#include "MovementHandlerAgentSprintActionTrigger_7a6120.h"

void MovementHandlerAgentSprintActionTrigger::SaveGame(BSPathingStreamWrite& a_stream) const
{
    a_stream.DoWriteUInt(eState);
    a_stream.DoWriteBool(bWantSprinting);
    a_stream.DoWriteBool(bCrippled);
}
