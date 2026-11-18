// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xe11eb0 BSPCGamepadDeviceHandler::Initialize
#include "BSPCGamepadDeviceHandler.h"
void BSPCGamepadDeviceHandler::Initialize()
{
    InitializeBase();
    if (gamepadAvailable) { InitializeDelegate(); }
}
