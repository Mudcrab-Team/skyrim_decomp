// Code origin: declarations written by hand from the local listings and the community headers; the bodies are in the matching .cpp.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// IngredientItem::GetData2, IngredientItem::IsFood, IngredientItem::InitChunk: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// GetData: GUESS(low); virtual slot 0x6C (byte offset 0x360), returns the record whose flags IsFood reads
// Unk_NN: GUESS(low); placeholders that only keep GetData at the vtable offset the image encodes
// IngredientData, cost, flags: STANDIN GUESS(low); the first two members of the record at 0x130 (cost, flags)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50, unk58, unk60, unk68, unk70, unk78, unk80, unk88, unk90, unk98, unkA0, unkA8, unkB0, unkB8, unkC0, unkC8, unkD0, unkD8, unkE0, unkE8, unkF0, unkF8, unk100, unk108, unk110, unk118, unk120, unk128: GUESS(low); storage not read by the compared code
#pragma once
#include <cstdint>
struct IngredientData {
    std::int32_t  cost;   // 00
    std::uint32_t flags;  // 04
};
class IngredientItem {
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual IngredientData* GetData() const;  // 6C
    virtual IngredientData* GetData2();
    virtual bool IsFood() const;
    virtual void InitChunk();

private:
    std::uint64_t unk08;  // 08
    std::uint64_t unk10;  // 10
    std::uint64_t unk18;  // 18
    std::uint64_t unk20;  // 20
    std::uint64_t unk28;  // 28
    std::uint64_t unk30;  // 30
    std::uint64_t unk38;  // 38
    std::uint64_t unk40;  // 40
    std::uint64_t unk48;  // 48
    std::uint64_t unk50;  // 50
    std::uint64_t unk58;  // 58
    std::uint64_t unk60;  // 60
    std::uint64_t unk68;  // 68
    std::uint64_t unk70;  // 70
    std::uint64_t unk78;  // 78
    std::uint64_t unk80;  // 80
    std::uint64_t unk88;  // 88
    std::uint64_t unk90;  // 90
    std::uint64_t unk98;  // 98
    std::uint64_t unkA0;  // A0
    std::uint64_t unkA8;  // A8
    std::uint64_t unkB0;  // B0
    std::uint64_t unkB8;  // B8
    std::uint64_t unkC0;  // C0
    std::uint64_t unkC8;  // C8
    std::uint64_t unkD0;  // D0
    std::uint64_t unkD8;  // D8
    std::uint64_t unkE0;  // E0
    std::uint64_t unkE8;  // E8
    std::uint64_t unkF0;  // F0
    std::uint64_t unkF8;  // F8
    std::uint64_t unk100;  // 100
    std::uint64_t unk108;  // 108
    std::uint64_t unk110;  // 110
    std::uint64_t unk118;  // 118
    std::uint64_t unk120;  // 120
    std::uint64_t unk128;  // 128
    int cost;
    std::uint32_t flags;
};
