// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x9622f0 QuickSaveLoadHandler::CanProcess
#include "QuickSaveLoadHandler_9622f0.h"

// Accept input events matching quick-save, quick-load, or the third configured user event.
bool QuickSaveLoadHandler::CanProcess(InputEvent* a_event)
{
    if (a_event->QUserEvent() == gUserEvents->quicksave) {
        return true;
    }
    if (a_event->QUserEvent() == gUserEvents->quickload) {
        return true;
    }
    if (a_event->QUserEvent() == gUserEvents->quickInventory) {
        return true;
    }
    return false;
}
