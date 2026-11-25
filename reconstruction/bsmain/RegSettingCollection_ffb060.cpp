// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00ab5a70::RegSettingCollection::CloseHandle_140D5DB00.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00aa0000_o2.cpp:24134
// 0xffb060 f3m_00ab5a70::RegSettingCollection::CloseHandle_140D5DB00
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00420000_o2.cpp:17948
// Adapted helpers: Release
#include "RegSettingCollection_ffb060.h"

namespace f3m_00ab5a70 {
bool RegSettingCollection::CloseHandle_140D5DB00() {
    bool result = true;
    if (key) {
        result = RegCloseKey(key) == 0;
        key = 0;
    }
    return result;
}
}
