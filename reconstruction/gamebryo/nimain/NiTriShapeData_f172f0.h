// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiTriShapeData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiTriShapeData::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_, padding_74_: GUESS(low); placeholder name
#pragma once

#include <string.h>

namespace f3m_00845ee0 {

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiTriShapeData
{
  public:
    char padding_0_[112];
    unsigned count;
    char padding_74_[4];
    unsigned short *data;
    bool Func008557e0(NiTriShapeData*);
    bool IsEqual(NiTriShapeData*);
};
}
