// Source exposure: mixed.
// Code origin: original; pinned-image observations and labelled naming sources.
// SPDX-License-Identifier: CC0-1.0
// 0xffb060 RegSettingCollection::CloseHandle
// Adapted bodies: none.
#include "RegSettingCollection_ffb060.h"

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* key);

bool RegSettingCollection::CloseHandle()
{
    if (handle) {
        long result = RegCloseKey(handle);
        handle = nullptr;
        return result == 0;
    }
    return true;
}
