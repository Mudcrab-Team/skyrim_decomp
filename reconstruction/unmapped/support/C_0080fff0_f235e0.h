// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// C_0080fff0: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// C_0080fff0::Func0080fff0: GUESS(low); placeholder name
// vslot_0_, vslot_1_, padding_8_: GUESS(low); placeholder name
#pragma once

struct Q_0080fff0;
struct R_0080fff0;





struct R_0080fff0 { char pad[4]; R_0080fff0* p; };
extern R_0080fff0 Data0108ec3c;
struct Q_0080fff0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual int v3(); };
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct C_0080fff0
{
  public:
    virtual void vslot_0_();
    virtual void vslot_1_();
    virtual R_0080fff0* v2();
    char padding_8_[40];
    int f24;
    int f28;
    Q_0080fff0 *f2c;
    bool Func0084a7c0(C_0080fff0* o);
    char Func0080fff0(C_0080fff0* o);
};
