// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xe7c2f0 BSPCOrbisGamepadDevice::SetRumble
// 0xe7c3b0 BSPCOrbisGamepadDevice::ProcessRawInput
#include "BSPCOrbisGamepadDevice.h"
#include <algorithm>
void BSPCOrbisGamepadDevice::SetRumble(float left,float right) { left*=255.0f; right*=255.0f; left=(std::max)(0.0f,left); right=(std::max)(0.0f,right); left=(std::min)(255.0f,left); right=(std::min)(255.0f,right); RumbleValues values{static_cast<std::uint8_t>(static_cast<std::int32_t>(left)),static_cast<std::uint8_t>(static_cast<std::int32_t>(right))}; ApplyRumble(userIndex,&values); }


