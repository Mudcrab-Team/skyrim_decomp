// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// RegSettingCollection: CRASHLOGGER_PDB(59818@2026.10.24)
// RegSettingCollection::OpenHandle: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <windows.h>

namespace f3m_00ab5a10 {

struct RegSettingCollection {
    virtual void v00();
    char keyName[260];
    HKEY hKey;
    bool OpenHandle(bool create);
};
}
