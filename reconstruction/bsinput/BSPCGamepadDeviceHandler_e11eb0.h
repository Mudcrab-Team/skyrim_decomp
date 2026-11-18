// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPCGamepadDeviceHandler, BSIInputDevice, Initialize, InitializeDelegate, currentPCGamePadDelegate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// gamepadAvailable, InitializeBase: GUESS(low)
#pragma once
class BSPCGamepadDeviceDelegate;
extern bool gamepadAvailable;
class BSIInputDevice { public: virtual ~BSIInputDevice(); void InitializeBase(); };
class BSPCGamepadDeviceHandler : public BSIInputDevice { public: void Initialize(); void InitializeDelegate(); BSPCGamepadDeviceDelegate* currentPCGamePadDelegate; };
