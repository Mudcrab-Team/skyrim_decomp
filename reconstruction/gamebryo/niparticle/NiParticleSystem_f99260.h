// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00c1b0b0_cls: GUESS(low); placeholder name
// Func00c1b0b0_cls::Func00c1b0b0: GUESS(low); placeholder name
// padding_1_, vslot_0_, vslot_1_, vslot_2_, vslot_3_, vslot_4_, vslot_5_, vslot_6_, vslot_7_, vslot_8_, vslot_9_, vslot_10_, vslot_11_, vslot_12_, vslot_13_, vslot_14_, vslot_15_, vslot_16_, vslot_17_, vslot_18_, vslot_19_, vslot_20_, vslot_21_, vslot_22_, vslot_23_, vslot_24_, vslot_25_: GUESS(low); placeholder name
// NiParticleSystem: GUESS(low); placeholder name
#pragma once

struct S_00c1b0b0_Item;
struct S_00c1b0b0_Obj;
struct S_00c1b0b0_Stream;


struct S_00c1b0b0_Stream;

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct S_00c1b0b0_Obj
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
    virtual void vslot_9_();
    virtual void vslot_10_();
    virtual void vslot_11_();
    virtual void vslot_12_();
    virtual void vslot_13_();
    virtual void vslot_14_();
    virtual void vslot_15_();
    virtual void vslot_16_();
    virtual void vslot_17_();
    virtual void vslot_18_();
    virtual void vslot_19_();
    virtual void vslot_20_();
    virtual void vslot_21_();
    virtual void vslot_22_();
    virtual void vslot_23_();
    virtual void vslot_24_();
    virtual void vslot_25_();
    virtual bool v21(S_00c1b0b0_Stream* kStream);
};

struct S_00c1b0b0_Item
{
    S_00c1b0b0_Item* m_pkNext;
    S_00c1b0b0_Item* m_pkPrev;
    S_00c1b0b0_Obj* m_element;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct S_00c1b0b0_Base
{
  public:
    bool Func00a9b190(S_00c1b0b0_Stream* kStream);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct Func00c1b0b0_cls : S_00c1b0b0_Base
{
  public:
    char padding_1_[359];
    S_00c1b0b0_Item *unkC8;
    bool Func00c1b0b0(S_00c1b0b0_Stream* kStream);
};

struct NiParticleSystem
{
};
