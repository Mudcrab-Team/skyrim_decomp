// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPCGamepadDeviceHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
// IsEnabled: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BSIInputDevice { public: virtual ~BSIInputDevice() {} virtual void Initialize(); virtual void Process(float); virtual bool IsEnabled() const; };
class BSPCGamepadDeviceDelegate : public BSIInputDevice {};
// IsEnabled: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BSPCGamepadDeviceHandler : public BSIInputDevice { public: BSPCGamepadDeviceHandler(); ~BSPCGamepadDeviceHandler() override; void Process(float) override; bool IsEnabled() const override; void InitializeDelegate(); BSPCGamepadDeviceDelegate* currentPCGamePadDelegate; };
static_assert(sizeof(BSPCGamepadDeviceHandler)==0x10,"gamepad handler size");
extern bool ProcessGamepadEnabledChange;

