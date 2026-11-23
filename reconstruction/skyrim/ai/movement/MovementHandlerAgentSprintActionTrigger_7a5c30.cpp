// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7a5c30 MovementHandlerAgentSprintActionTrigger::Function7a5c30
// Adapted bodies: none
#include "MovementHandlerAgentSprintActionTrigger_7a5c30.h"

void MovementHandlerAgentSprintActionTrigger::Function7a5c30()
{
    if (unk30) {
        unk30->Unregister(IMovementSetSprinting::QClassType());
        unk30 = nullptr;
    }
}
