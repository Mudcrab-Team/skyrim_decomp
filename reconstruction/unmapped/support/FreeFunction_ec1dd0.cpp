// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xec1dd0 Functionec1dd0
// Adapted bodies: none
#include "FreeFunction_ec1dd0.h"

// Waits indefinitely on the event handle at (slotIndex, eventIndex) when the slot is active.
// The community name table calls this WaitForJobTask (a hint, not proof); the names in this unit are stand-ins.
void Functionec1dd0(std::uint32_t slotIndex, std::uint32_t eventIndex)
{
    JobEventSlot_ec1dd0* slot = g_jobManager_ec1dd0->slots[slotIndex];
    if (slot != nullptr) {
        WaitForSingleObject(slot->events[eventIndex], 0xFFFFFFFFu);
    }
}
