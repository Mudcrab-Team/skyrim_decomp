// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiControllerManager: CRASHLOGGER_PDB(59818@2026.10.24)
// NiControllerManager::Routine14029FB70: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_, padding_68_, vslot_0_, vslot_1_, vslot_2_, vslot_3_, vslot_4_, vslot_5_, vslot_6_, vslot_7_, vslot_8_, vslot_9_, vslot_10_, vslot_11_, vslot_12_, vslot_13_, vslot_14_, vslot_15_, vslot_16_, vslot_17_, vslot_18_, vslot_19_, vslot_20_, vslot_21_, vslot_22_, vslot_23_, vslot_24_, vslot_25_, vslot_26_, vslot_27_, vslot_28_, vslot_29_, vslot_30_, vslot_31_, vslot_32_, vslot_33_, vslot_34_, vslot_35_, vslot_36_: GUESS(low); placeholder name
#pragma once

struct AnimatedItemV;
struct RefObj;
struct T1e4;

struct C78 { char pad[0x78]; void* x78; };

struct RefObj {
    virtual void unk00();
    virtual void Destroy();
    long refCount;
    const char* name;
};

struct U8 { void Func0049dfc0(RefObj*); };

struct T1e4 { char pad[8]; U8* u8; char pad2[0xd8 - 0xc]; C78* xd8; };

struct Unk34 {
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual T1e4* vf1e4();
    int Func006f7370();
    void Func006ff040(int, int);
};


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class AnimatedItemV
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
    virtual void Update(float time, bool force);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class NiControllerManager
{
  public:
    char padding_0_[96];
    AnimatedItemV **items;
    char padding_68_[4];
    unsigned int count;
    void Routine14029FB70(float time);
};
