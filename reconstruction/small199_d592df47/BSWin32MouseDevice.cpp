// BSWin32MouseDevice, Func3, MemoryManager, ReleaseDevice, memoryManager, Device: GUESS(low)
// ScatterTable, allocatorPad, device, pad0C, deviceButtons, buttonNameIDMap, backgroundMouse, dInputDevice, _pad00, _pad08, _capacity, _free, _good, _sentinel, _entries: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body and public prefix adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xe13280 BSWin32MouseDevice::Release

#include "BSWin32MouseDevice.h"
void BSWin32MouseDevice::Func3() { memoryManager->ReleaseDevice(dInputDevice); dInputDevice = nullptr; }
