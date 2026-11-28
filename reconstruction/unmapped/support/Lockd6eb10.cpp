// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xd6eb10 Lockd6eb10::Lockd6eb10
// CI hash: 0xd6eb10 ??0Lockd6eb10@@QEAA@I@Z
// Adapted bodies: none
#include "Lockd6eb10.h"

// Lazily resolves InitializeCriticalSectionAndSpinCount and initializes cs with spinCount or falls back.
Lockd6eb10::Lockd6eb10(std::uint32_t spinCount)
{
    InitSpinCountFn_d6eb10 initFn;
    if (!g_spinInitResolved_d6eb10) {
        void* kernel32 = GetModuleHandleA("kernel32.dll");
        initFn = reinterpret_cast<InitSpinCountFn_d6eb10>(
            GetProcAddress(kernel32, "InitializeCriticalSectionAndSpinCount"));
        g_initSpinCountFn_d6eb10 = initFn;
        g_spinInitResolved_d6eb10 = true;
    } else {
        initFn = g_initSpinCountFn_d6eb10;
    }

    if (initFn != nullptr) {
        initFn(&cs, spinCount);
    } else {
        InitializeCriticalSection(&cs);
    }
}
