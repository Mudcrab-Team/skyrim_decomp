// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xec1d30 Functionec1d30
// Adapted bodies: none
#include "FreeFunction_ec1d30.h"

// Signals the current thread's job event handle at eventIndex when the thread slot is active.
// The community name table calls this SetJobTaskEvent (a hint, not proof); the names in this unit are stand-ins.
void Functionec1d30(std::uint32_t eventIndex)
{
    JobEventSlot_ec1d30* slot = g_jobManager_ec1d30->slots[g_threadIndex_tls_0x880];
    if (slot != nullptr) {
        SetEvent(slot->events[eventIndex]);
    }
}
