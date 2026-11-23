// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/TESForm.h for TESForm.
// TESObjectREFR, TESObjectREFR::GetSaveParentCell, TESObjectREFR::parentCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR::Function2f3da0: GUESS(low)
// TESObjectCELL, TESWorldSpace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL::cellFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; byte view of low flag byte
// TESObjectCELL::worldSpace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; AE/1.7.104 offset 0x128
// unk00, unk41, unknown20, unknown68, VSlot3B_96: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include "declarations/TESForm.h"

class TESWorldSpace;

class TESObjectCELL
{
public:
    std::uint8_t unk00[0x40];  // 00
    std::uint8_t cellFlags;  // 40
    std::uint8_t unk41[0xE7];  // 41
    TESWorldSpace* worldSpace;  // 128
};
static_assert(offsetof(TESObjectCELL, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(TESObjectCELL, worldSpace) == 0x128, "worldSpace offset");

class TESObjectREFR : public TESForm
{
public:
    ~TESObjectREFR() override;  // 00
    virtual void VSlot3B_96_00();  // 3B
    virtual void VSlot3B_96_01();  // 3C
    virtual void VSlot3B_96_02();  // 3D
    virtual void VSlot3B_96_03();  // 3E
    virtual void VSlot3B_96_04();  // 3F
    virtual void VSlot3B_96_05();  // 40
    virtual void VSlot3B_96_06();  // 41
    virtual void VSlot3B_96_07();  // 42
    virtual void VSlot3B_96_08();  // 43
    virtual void VSlot3B_96_09();  // 44
    virtual void VSlot3B_96_0A();  // 45
    virtual void VSlot3B_96_0B();  // 46
    virtual void VSlot3B_96_0C();  // 47
    virtual void VSlot3B_96_0D();  // 48
    virtual void VSlot3B_96_0E();  // 49
    virtual void VSlot3B_96_0F();  // 4A
    virtual void VSlot3B_96_10();  // 4B
    virtual void VSlot3B_96_11();  // 4C
    virtual void VSlot3B_96_12();  // 4D
    virtual void VSlot3B_96_13();  // 4E
    virtual void VSlot3B_96_14();  // 4F
    virtual void VSlot3B_96_15();  // 50
    virtual void VSlot3B_96_16();  // 51
    virtual void VSlot3B_96_17();  // 52
    virtual void VSlot3B_96_18();  // 53
    virtual void VSlot3B_96_19();  // 54
    virtual void VSlot3B_96_1A();  // 55
    virtual void VSlot3B_96_1B();  // 56
    virtual void VSlot3B_96_1C();  // 57
    virtual void VSlot3B_96_1D();  // 58
    virtual void VSlot3B_96_1E();  // 59
    virtual void VSlot3B_96_1F();  // 5A
    virtual void VSlot3B_96_20();  // 5B
    virtual void VSlot3B_96_21();  // 5C
    virtual void VSlot3B_96_22();  // 5D
    virtual void VSlot3B_96_23();  // 5E
    virtual void VSlot3B_96_24();  // 5F
    virtual void VSlot3B_96_25();  // 60
    virtual void VSlot3B_96_26();  // 61
    virtual void VSlot3B_96_27();  // 62
    virtual void VSlot3B_96_28();  // 63
    virtual void VSlot3B_96_29();  // 64
    virtual void VSlot3B_96_2A();  // 65
    virtual void VSlot3B_96_2B();  // 66
    virtual void VSlot3B_96_2C();  // 67
    virtual void VSlot3B_96_2D();  // 68
    virtual void VSlot3B_96_2E();  // 69
    virtual void VSlot3B_96_2F();  // 6A
    virtual void VSlot3B_96_30();  // 6B
    virtual void VSlot3B_96_31();  // 6C
    virtual void VSlot3B_96_32();  // 6D
    virtual void VSlot3B_96_33();  // 6E
    virtual void VSlot3B_96_34();  // 6F
    virtual void VSlot3B_96_35();  // 70
    virtual void VSlot3B_96_36();  // 71
    virtual void VSlot3B_96_37();  // 72
    virtual void VSlot3B_96_38();  // 73
    virtual void VSlot3B_96_39();  // 74
    virtual void VSlot3B_96_3A();  // 75
    virtual void VSlot3B_96_3B();  // 76
    virtual void VSlot3B_96_3C();  // 77
    virtual void VSlot3B_96_3D();  // 78
    virtual void VSlot3B_96_3E();  // 79
    virtual void VSlot3B_96_3F();  // 7A
    virtual void VSlot3B_96_40();  // 7B
    virtual void VSlot3B_96_41();  // 7C
    virtual void VSlot3B_96_42();  // 7D
    virtual void VSlot3B_96_43();  // 7E
    virtual void VSlot3B_96_44();  // 7F
    virtual void VSlot3B_96_45();  // 80
    virtual void VSlot3B_96_46();  // 81
    virtual void VSlot3B_96_47();  // 82
    virtual void VSlot3B_96_48();  // 83
    virtual void VSlot3B_96_49();  // 84
    virtual void VSlot3B_96_4A();  // 85
    virtual void VSlot3B_96_4B();  // 86
    virtual void VSlot3B_96_4C();  // 87
    virtual void VSlot3B_96_4D();  // 88
    virtual void VSlot3B_96_4E();  // 89
    virtual void VSlot3B_96_4F();  // 8A
    virtual void VSlot3B_96_50();  // 8B
    virtual void VSlot3B_96_51();  // 8C
    virtual void VSlot3B_96_52();  // 8D
    virtual void VSlot3B_96_53();  // 8E
    virtual void VSlot3B_96_54();  // 8F
    virtual void VSlot3B_96_55();  // 90
    virtual void VSlot3B_96_56();  // 91
    virtual void VSlot3B_96_57();  // 92
    virtual void VSlot3B_96_58();  // 93
    virtual void VSlot3B_96_59();  // 94
    virtual void VSlot3B_96_5A();  // 95
    virtual void VSlot3B_96_5B();  // 96
    virtual TESObjectCELL* GetSaveParentCell() const;  // 97

    bool Function2f3da0() const;  // compared: 0x2f3da0

    std::uint8_t unknown20[0x40];  // 20
    TESObjectCELL* parentCell;  // 60
    std::uint8_t unknown68[0x30];  // 68
};
static_assert(offsetof(TESObjectREFR, parentCell) == 0x60, "parentCell offset");
static_assert(sizeof(TESObjectREFR) == 0x98, "TESObjectREFR size");
