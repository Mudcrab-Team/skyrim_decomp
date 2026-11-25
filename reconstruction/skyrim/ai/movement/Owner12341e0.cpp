// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x7a5c30 (skyrim/ai/movement/MovementHandlerAgentSprintActionTrigger_7a5c30): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0x12341e0 Owner12341e0::Function12341e0
#include "Owner12341e0.h"

// guess: same compiled code as matched 0x7a5c30 apart from relocated fields; its role here is not established.
void Owner12341e0::Function12341e0()
{
    if (unk30) {
        unk30->Unregister(IMovementSetSprinting::QClassType());
        unk30 = nullptr;
    }
}
