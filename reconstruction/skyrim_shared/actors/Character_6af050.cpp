// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6af050 Character::QueryMovementInterfaceState
// Adapted bodies: none
#include "Character_6af050.h"

bool Character::QueryMovementInterfaceState()
{
    bool result = false;
    MovementControllerNPC* controller = movementController.get();
    if (controller) {
        IMovementInterface* movementInterface = controller->Unk_03(&movementInterfaceId);
        if (movementInterface) {
            result = movementInterface->QueryState();
        }
    }
    return result;
}
