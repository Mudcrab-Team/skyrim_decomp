// Source exposure: mixed (pinned-image observations; labelled declarations).
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: CC0-1.0
// 0x7a6170 MovementHandlerAgentSprintActionTrigger::Func12_1406FD830
// Adapted bodies: none
#include "MovementHandlerAgentSprintActionTrigger_7a6170.h"

void MovementHandlerAgentSprintActionTrigger::Func12_1406FD830(BSPathingStreamRead& stream)
{
    if (stream.GetVersion() >= 29) {
        std::uint32_t state;
        stream.ReadState(state);
        eState = state;
    } else {
        eState = 0;
    }
    stream.ReadBool(bWantSprinting);
    stream.ReadBool(bCrippled);
}
