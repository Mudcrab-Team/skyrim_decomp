// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x962180 MenuOpenHandler::CanProcess
#include "MenuOpenHandler_962180.h"

// Return whether the input event opens a permitted menu under the current pause and lock state.
bool MenuOpenHandler::CanProcess(InputEvent* a_event)
{
    bool alwaysAllowed = (a_event->QUserEvent() == gUserEvents->unk60 ||
                          a_event->QUserEvent() == gUserEvents->unk80);
    bool gameMenuAllowed = (!gUIPauseState->GameIsPaused() && gMenuControlsState->unk20 == 0);
    bool canProcess = alwaysAllowed;
    if (!canProcess) {
        canProcess = gameMenuAllowed &&
            (a_event->QUserEvent() == gUserEvents->unk118 ||
             a_event->QUserEvent() == gUserEvents->unk2B0 ||
             a_event->QUserEvent() == gUserEvents->unk288 ||
             a_event->QUserEvent() == gUserEvents->unk290 ||
             a_event->QUserEvent() == gUserEvents->unk298 ||
             a_event->QUserEvent() == gUserEvents->unk2A0 ||
             a_event->QUserEvent() == gUserEvents->unk110);
    }
    if (gDisableMenus) {
        return false;
    }
    return canProcess;
}
