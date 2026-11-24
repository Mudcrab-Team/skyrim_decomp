// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// bhkConvexShape: CRASHLOGGER_PDB(59818@2026.10.24)
// bhkConvexShape::SaveBinary_140DDD700: CRASHLOGGER_PDB(59818@2026.10.24)
// vslot_0_, vslot_1_, vslot_2_, vslot_3_, vslot_4_, vslot_5_, vslot_6_, vslot_7_, vslot_8_, vslot_9_, vslot_10_, vslot_11_, vslot_12_, vslot_13_, vslot_14_, vslot_15_, vslot_16_, vslot_17_, vslot_18_, vslot_19_, vslot_20_, vslot_21_, vslot_22_, vslot_23_, vslot_24_, vslot_25_, vslot_26_, vslot_27_, vslot_28_, vslot_29_, vslot_30_, vslot_31_, vslot_32_, vslot_33_, vslot_34_, vslot_35_, vslot_36_, vslot_37_, vslot_38_, vslot_39_, vslot_40_, vslot_41_, vslot_42_, vslot_43_, vslot_44_, vslot_45_, vslot_46_, padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

// Byte-swap intrinsic: the target code swaps the field with a bswap instruction.
extern "C" unsigned long _byteswap_ulong(unsigned long);

struct C9FC00Data;
struct C9FC00Stream;



// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct C9FC00Stream
{
  public:
    char padding_0_[524];
    unsigned char m_ucEndian;
};

struct C9FC00Data
{
    int unk00;
    unsigned long m_ulValue;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class bhkConvexShape
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
    virtual void vslot_26_();
    virtual void vslot_27_();
    virtual void vslot_28_();
    virtual void vslot_29_();
    virtual void vslot_30_();
    virtual void vslot_31_();
    virtual void vslot_32_();
    virtual void vslot_33_();
    virtual void vslot_34_();
    virtual void vslot_35_();
    virtual void vslot_36_();
    virtual void vslot_37_();
    virtual void vslot_38_();
    virtual void vslot_39_();
    virtual void vslot_40_();
    virtual void vslot_41_();
    virtual void vslot_42_();
    virtual void vslot_43_();
    virtual void vslot_44_();
    virtual void vslot_45_();
    virtual void vslot_46_();
    virtual C9FC00Data* GetData(bool* pbValid);
    void SaveBinaryBase(C9FC00Stream& kStream);
    void SaveBinary_140DDD700(C9FC00Stream& kStream);
};

struct Globals
{
};
