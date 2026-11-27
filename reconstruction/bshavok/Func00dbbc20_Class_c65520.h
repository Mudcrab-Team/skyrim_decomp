// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00dbbc20_Class: GUESS(low); placeholder name
// Func00dbbc20_Class::Func00dbbc20: GUESS(low); placeholder name
// padding_8_, vslot_0_, vslot_1_, vslot_2_, vslot_3_, vslot_4_, vslot_5_, vslot_6_, vslot_7_, vslot_8_: GUESS(low); placeholder name
#pragma once

namespace fnv_00dbbc20 {
struct D481D0Class;


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct D481D0Class
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
    virtual int Func00dbbc20_10(char const* name);
    char const* getName() const;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct Func00dbbc20_Class : D481D0Class
{
  public:
    char padding_8_[16];
    D481D0Class *m_20;
    D481D0Class *m_0C;
    int Func00dbbc20();
};

}
