// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x998f80 MapZoomHandler::CanProcess
#include "MapZoomHandler_998f80.h"

// Return whether the input event is a map zoom-in or zoom-out control.
bool MapZoomHandler::CanProcess(InputEvent* a_event)
{
    if (a_event->QUserEvent() == gUserEvents->unk1E8) {
        return true;
    }
    if (a_event->QUserEvent() == gUserEvents->unk1F0) {
        return true;
    }
    return false;
}
