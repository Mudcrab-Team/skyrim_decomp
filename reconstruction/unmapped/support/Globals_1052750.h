// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// SetFlagRecursive: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// vslot_0_, vslot_1_, vslot_2_, padding_8_, padding_48_, padding_120_, padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct FlaggedObj_cls;
struct WalkNode_cls;


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct FlaggedObj_cls
{
  public:
    char padding_0_[24];
    unsigned short m_0c;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct WalkNode_cls
{
  public:
    virtual void vslot_0_();
    virtual void vslot_1_();
    virtual void vslot_2_();
    virtual WalkNode_cls* v03();
    char padding_8_[56];
    FlaggedObj_cls *m_1c;
    char padding_48_[208];
    WalkNode_cls **m_a0;
    char padding_120_[2];
    unsigned short m_a6;
};

struct Globals
{
};
