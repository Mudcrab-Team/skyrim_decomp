// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x7a3750 MovementHandlerAgentDirectControl::~MovementHandlerAgentDirectControl
// CI hash: 0x7a3750 ??_GMovementHandlerAgentDirectControl@@UEAAPEAXI@Z
// Adapted bodies: MovementHandlerAgentDirectControl::~MovementHandlerAgentDirectControl from the sibling source named in the header
#include "MovementHandlerAgentDirectControl_7a3750.h"

MovementHandlerAgentDirectControl::MovementHandlerAgentDirectControl()
    : MovementHandlerAgent()
{
    pRegisterInterface = nullptr;
}

MovementHandlerAgentDirectControl::~MovementHandlerAgentDirectControl()
{
    if (pRegisterInterface) {
        pRegisterInterface = nullptr;
    }
}
