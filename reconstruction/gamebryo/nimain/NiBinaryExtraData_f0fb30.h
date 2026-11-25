// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiBinaryExtraData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryExtraData::IsEqual: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// padding_0_: GUESS(low); placeholder name
#pragma once

#include <string.h>


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiBinaryExtraData
{
  public:
    char padding_0_[24];
    char *m_pByteBuffer;
    unsigned int m_uiSize;
    bool IsEqual(const NiBinaryExtraData* pkOther) const;
};
