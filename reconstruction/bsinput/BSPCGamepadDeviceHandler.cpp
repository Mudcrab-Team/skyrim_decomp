// Source exposure: mixed (community headers and pinned-image analysis).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: brown-room reconstruction from disassembly
// 0xe11ee0 BSPCGamepadDeviceHandler::Process
// 0xe11f30 BSPCGamepadDeviceHandler::Shutdown
// 0xe11f50 BSPCGamepadDeviceHandler::GetButtonNameFromID
// 0xe11f90 BSPCGamepadDeviceHandler::GetKeyCodeFromID
// 0xe11fb0 BSPCGamepadDeviceHandler::ClearInputState
// 0xe11f70 BSPCGamepadDeviceHandler::Functione11f70
// 0xe12390 BSPCGamepadDeviceHandler::~BSPCGamepadDeviceHandler
// 0xe12490 BSPCGamepadDeviceHandler::IsEnabled
#include "BSPCGamepadDeviceHandler.h"
// GamepadDelegateStub: GUESS(low); local view of the delegate's vtable slot 5, whose header name is
// not used here so the call keeps the shape that was compared.
class GamepadDelegateStub
{
public:
    virtual ~GamepadDelegateStub() = default;
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual bool Slot04();
    virtual std::uint32_t Slot05();
};
std::uint32_t BSPCGamepadDeviceHandler::Functione11f70() const
{
    if (currentPCGamePadDelegate) {
        return reinterpret_cast<GamepadDelegateStub*>(currentPCGamePadDelegate)->Slot05();
    }
    return 0xFFFFFFFFu;
}
BSPCGamepadDeviceHandler::BSPCGamepadDeviceHandler() {}
BSPCGamepadDeviceHandler::~BSPCGamepadDeviceHandler() { if (currentPCGamePadDelegate) delete currentPCGamePadDelegate; }
void BSPCGamepadDeviceHandler::Process(float a_elapsed) { if (!currentPCGamePadDelegate) { if (!ProcessGamepadEnabledChange) return; InitializeDelegate(); if (!currentPCGamePadDelegate) return; } currentPCGamePadDelegate->Process(a_elapsed); }
void BSPCGamepadDeviceHandler::Shutdown() { if (!currentPCGamePadDelegate) return; currentPCGamePadDelegate->Shutdown(); }
bool BSPCGamepadDeviceHandler::GetButtonNameFromID(std::int32_t a_id, char32_t* a_name) { if (currentPCGamePadDelegate) return currentPCGamePadDelegate->GetButtonNameFromID(a_id, a_name); return false; }
bool BSPCGamepadDeviceHandler::GetKeyCodeFromID(std::int32_t a_id, std::uint32_t* a_code) { if (currentPCGamePadDelegate) return currentPCGamePadDelegate->GetKeyCodeFromID(a_id, a_code); return false; }
void BSPCGamepadDeviceHandler::ClearInputState() { if (!currentPCGamePadDelegate) return; currentPCGamePadDelegate->ClearInputState(); }
bool BSPCGamepadDeviceHandler::IsEnabled() const { return currentPCGamePadDelegate != nullptr; }
