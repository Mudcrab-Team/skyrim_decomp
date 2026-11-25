// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original event filtering from the assigned local pack; community declarations only.
// FreeCameraState, CanProcess, InputEvent, QUserEvent, UserEvents, run: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FreeCameraState::CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// userEvents, additionalEvent1, additionalEvent2, additionalEvent3, additionalEvent4, additionalEvent5: GUESS(low); private reference slots only
// 0x8f6100 FreeCameraState::CanProcess
#include "FreeCameraState_8f6100.h"

bool FreeCameraState::CanProcess(InputEvent* event)
{
    const char* id = event->QUserEvent().data;
    if (id == userEvents->run || id == additionalEvent1 ||
        id == additionalEvent2 || id == additionalEvent3 ||
        id == additionalEvent4 || id == additionalEvent5)
        return true;
    return false;
}
