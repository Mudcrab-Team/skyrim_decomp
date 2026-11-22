// Source exposure: mixed (community headers and pinned-image analysis).
// Code origin: existing unit plus original reconstruction of SetLEDColor and ResetLEDColor. Adapted bodies: none.
// Recipe: reconstruction/recipes/o2-fpfast.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xe7c2f0 BSPCOrbisGamepadDevice::SetRumble
// 0xe7c350 BSPCOrbisGamepadDevice::SetLEDColor
// 0xe7c390 BSPCOrbisGamepadDevice::ResetLEDColor
#include "BSPCOrbisGamepadDevice.h"
void BSPCOrbisGamepadDevice::SetRumble(float left,float right) { left*=255.0f; right*=255.0f; if (left < 0.0f) left = 0.0f; if (right < 0.0f) right = 0.0f; if (left > 255.0f) left = 255.0f; if (right > 255.0f) right = 255.0f; RumbleValues values{static_cast<std::uint8_t>(static_cast<std::int32_t>(left)),static_cast<std::uint8_t>(static_cast<std::int32_t>(right))}; ApplyRumble(userIndex,&values); }

void BSPCOrbisGamepadDevice::SetLEDColor(const LEDColorInput* a_color)
{
    PadLightBarParam param{};
    param.r = static_cast<std::uint8_t>(a_color->r);
    param.g = static_cast<std::uint8_t>(a_color->g);
    param.b = static_cast<std::uint8_t>(a_color->b);
    ApplyPadLightBar(userIndex, &param);
}

void BSPCOrbisGamepadDevice::ResetLEDColor()
{
    ResetPadLightBar(userIndex);
}
