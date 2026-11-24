// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiSwitchStringExtraData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiSwitchStringExtraData::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_, padding_1c_: GUESS(low); placeholder name
#pragma once

#include <string.h>



extern "C" int strcmp(const char*, const char*);

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class NiSwitchStringExtraData
{
  public:
    char padding_0_[24];
    unsigned int m_uiSize;
    char padding_1c_[4];
    char **m_ppcStrings;
    int m_iType;
    bool IsEqual(NiSwitchStringExtraData* pkOther);
};
