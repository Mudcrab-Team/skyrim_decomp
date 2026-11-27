// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkAvoidBox: CRASHLOGGER_PDB(59818@2026.10.24)
// hkAvoidBox::Func15_140DE6C30: CRASHLOGGER_PDB(59818@2026.10.24)
// vslot_0_, vslot_1_, vslot_2_, vslot_3_, vslot_4_, vslot_5_, vslot_6_, vslot_7_, vslot_8_, vslot_9_, vslot_10_, vslot_11_, vslot_12_, vslot_13_, vslot_14_, vslot_15_, padding_8_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct ClassLayout_91ab10;


struct hkAvoidBox
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    hkAvoidBox** unk28;
    int unk2c;

    int Func15_140DE6C30();
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct ClassLayout_91ab10
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
    virtual int s38(int index);
    char padding_8_[304];
    int m_count;
};

struct Globals
{
};
