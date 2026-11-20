// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xe11ee0 BSPCGamepadDeviceHandler::Process
// 0xe12390 BSPCGamepadDeviceHandler::~BSPCGamepadDeviceHandler
// 0xe12490 BSPCGamepadDeviceHandler::IsEnabled
#include "BSPCGamepadDeviceHandler.h"
BSPCGamepadDeviceHandler::BSPCGamepadDeviceHandler() {}
BSPCGamepadDeviceHandler::~BSPCGamepadDeviceHandler() { if(currentPCGamePadDelegate) delete currentPCGamePadDelegate; }
void BSPCGamepadDeviceHandler::Process(float elapsed) { if(!currentPCGamePadDelegate) { if(!ProcessGamepadEnabledChange) return; InitializeDelegate(); if(!currentPCGamePadDelegate) return; } currentPCGamePadDelegate->Process(elapsed); }
bool BSPCGamepadDeviceHandler::IsEnabled() const { return currentPCGamePadDelegate != nullptr; }

