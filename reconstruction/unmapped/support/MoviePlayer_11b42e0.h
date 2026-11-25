// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// MoviePlayer: CRASHLOGGER_PDB(59818@2026.10.24)
// MoviePlayer::CalculateScale: CRASHLOGGER_PDB(59818@2026.10.24)
// vslot_0_, vslot_1_, vslot_2_, vslot_3_, vslot_4_, vslot_5_, vslot_6_, vslot_7_, vslot_8_: GUESS(low); placeholder name
#pragma once

namespace f3m_007fb000 {

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct MoviePlayer
{
  public:
    virtual void vslot_0_();
    virtual void vslot_1_();
    virtual void vslot_2_();
    virtual void vslot_3_();
    virtual void vslot_4_();
    virtual void vslot_5_();
    virtual void vslot_6_();
    virtual void vslot_7_();
    virtual void vslot_8_();
    virtual unsigned int GetFirst();
    virtual unsigned int GetSecond();
    float CalculateScale(unsigned int divisorA, unsigned int divisorB, bool useFirst);
};
}
