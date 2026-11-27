// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpEntityListener: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpEntityListener::EntityShapeSetCallback: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

namespace f3m_004d31c0 {
struct Argument867;


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct Argument867
{
  public:
    char padding_0_[16];
    unsigned __int64 count08;
};
struct hkpEntityListener {
    virtual void slot00();
    virtual void slot04(Argument867* argument);
    virtual void slot08(Argument867* argument);
    void EntityShapeSetCallback(Argument867* argument);
};
}

struct Globals
{
};
