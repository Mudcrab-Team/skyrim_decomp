// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPCGamepadDeviceHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
class BSIInputDevice { public: virtual ~BSIInputDevice() {} virtual void Initialize(); virtual void Process(float); };
class BSPCGamepadDeviceDelegate : public BSIInputDevice {};
class BSPCGamepadDeviceHandler : public BSIInputDevice { public: BSPCGamepadDeviceHandler(); ~BSPCGamepadDeviceHandler() override; void Process(float) override; void InitializeDelegate(); BSPCGamepadDeviceDelegate* currentPCGamePadDelegate; };
static_assert(sizeof(BSPCGamepadDeviceHandler)==0x10,"gamepad handler size");
extern bool ProcessGamepadEnabledChange;

