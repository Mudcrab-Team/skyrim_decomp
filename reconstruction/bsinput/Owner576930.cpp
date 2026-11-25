// Source exposure: mixed (community headers and pinned-image analysis).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: brown-room reconstruction from disassembly Stamped as a twin of matched 0xe12490 (bsinput/BSPCGamepadDeviceHandler): source copied, names replaced by placeholders.
// 0x576930 Owner576930::IsEnabled
#include "Owner576930.h"

Owner576930::Owner576930() {}

// guess: same compiled code as matched 0xe12490 apart from relocated fields; its role here is not established.
bool Owner576930::IsEnabled() const { return currentPCGamePadDelegate != nullptr; }
