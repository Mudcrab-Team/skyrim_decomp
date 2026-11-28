// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x998af0 MapLookHandler::CanProcess
#include "MapLookHandler_998af0.h"

// Return whether the input event is a map look or camera pan control.
bool MapLookHandler::CanProcess(InputEvent* a_event)
{
    if (a_event->QUserEvent() == gUserEvents->unk2C0) {
        return true;
    }
    if (a_event->QUserEvent() == gUserEvents->unk30) {
        return true;
    }
    if (unk18 && a_event->QUserEvent() == gUserEvents->unk180) {
        return true;
    }
    if (a_event->QUserEvent() == gUserEvents->unk138) {
        return true;
    }
    if (a_event->QUserEvent() == gUserEvents->unk140) {
        return true;
    }
    if (a_event->QUserEvent() == gUserEvents->unk148) {
        return true;
    }
    if (a_event->QUserEvent() == gUserEvents->unk150) {
        return true;
    }
    return false;
}
