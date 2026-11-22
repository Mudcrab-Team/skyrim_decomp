// Source exposure: mixed (community headers; the pinned image listing).
// 0xe11f90 compared function
// 0xe11f70 compared function
// 0xe11f50 compared function
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0xe11fb0 BSPCGamepadDeviceHandler::Functione11fb0
// Adapted bodies: none
// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0xe11f30 BSPCGamepadDeviceHandler::Functione11f30
// Adapted bodies: none
// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#include "BSPCGamepadDeviceHandler.h"

// GamepadDelegateStub: GUESS(low); local view of the delegate's vtable slots 3 to 8.
class GamepadDelegateStub
{
public:
    virtual ~GamepadDelegateStub() = default;
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual bool Slot04();
    virtual std::uint32_t Slot05();
    virtual bool Slot06();
    virtual void Slot07();
    virtual void Slot08();
};

void BSPCGamepadDeviceHandler::Functione11f30()
{
    if (currentPCGamePadDelegate) {
        reinterpret_cast<GamepadDelegateStub*>(currentPCGamePadDelegate)->Slot03();
    }
}

bool BSPCGamepadDeviceHandler::Functione11f50() const
{
    if (currentPCGamePadDelegate) {
        return reinterpret_cast<GamepadDelegateStub*>(currentPCGamePadDelegate)->Slot04();
    }
    return false;
}

std::uint32_t BSPCGamepadDeviceHandler::Functione11f70() const
{
    if (currentPCGamePadDelegate) {
        return reinterpret_cast<GamepadDelegateStub*>(currentPCGamePadDelegate)->Slot05();
    }
    return 0xFFFFFFFFu;
}

bool BSPCGamepadDeviceHandler::Functione11f90() const
{
    if (currentPCGamePadDelegate) {
        return reinterpret_cast<GamepadDelegateStub*>(currentPCGamePadDelegate)->Slot06();
    }
    return false;
}

void BSPCGamepadDeviceHandler::Functione11fb0()
{
    if (currentPCGamePadDelegate) {
        reinterpret_cast<GamepadDelegateStub*>(currentPCGamePadDelegate)->Slot08();
    }
}

BSPCGamepadDeviceHandler::BSPCGamepadDeviceHandler() {}
BSPCGamepadDeviceHandler::~BSPCGamepadDeviceHandler() { if(currentPCGamePadDelegate) delete currentPCGamePadDelegate; }
void BSPCGamepadDeviceHandler::Process(float elapsed) { if(!currentPCGamePadDelegate) { if(!ProcessGamepadEnabledChange) return; InitializeDelegate(); if(!currentPCGamePadDelegate) return; } currentPCGamePadDelegate->Process(elapsed); }
bool BSPCGamepadDeviceHandler::IsEnabled() const { return currentPCGamePadDelegate != nullptr; }

