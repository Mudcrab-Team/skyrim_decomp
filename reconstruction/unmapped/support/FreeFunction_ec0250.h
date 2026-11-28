// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Functionec0250, WinCall_ec0250, GetLastError, handle: GUESS(low)
#pragma once

#include <cstdint>

extern "C" {
__declspec(dllimport) int __stdcall WinCall_ec0250(void* handle);
__declspec(dllimport) unsigned long __stdcall GetLastError();
}

std::uint32_t Functionec0250(void* handle);
