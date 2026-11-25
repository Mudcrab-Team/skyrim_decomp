// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00ab5a10::RegSettingCollection::OpenHandle.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00aa0000_o2_2.cpp:1568
// 0xffafe0 f3m_00ab5a10::RegSettingCollection::OpenHandle
#include "RegSettingCollection_ffafe0.h"

namespace f3m_00ab5a10 {
bool RegSettingCollection::OpenHandle(bool create)
{
    DWORD disposition;
    bool result = false;
    if (create)
        result = (RegCreateKeyExA(HKEY_LOCAL_MACHINE, keyName, 0, 0, 0, KEY_ALL_ACCESS, 0, &hKey, &disposition) == 0);
    else
        result = (RegOpenKeyExA(HKEY_LOCAL_MACHINE, keyName, 0, KEY_ALL_ACCESS, &hKey) == 0);
    return result;
}
}
