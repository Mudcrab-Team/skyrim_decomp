// AlchemyItem declarations for build sse-steam-1-7-104 (standalone unit for the functions compared in the matching .cpp).
// Code origin: declarations written by hand from the local listings and the community headers; the bodies are in the matching .cpp.
// AlchemyItem partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// unknown00, cost, flags, InitializeMagicData, RemoveAllEffects, ClearFormData: STANDIN GUESS(low)
// GetData2, IsMedicine, IsPoison, IsFood: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// GetData: GUESS(low); virtual slot 0x6C (byte offset 0x360), returns the record whose flags the three tests read
// Unk_61: GUESS(low); virtual slot 0x61 (byte offset 0x308), a bool test called by IsFood
// Unk_NN: GUESS(low); placeholders that only keep Unk_61 and GetData at the vtable offsets the image encodes
// AlchemyData: STANDIN GUESS(low); the first two members of the record at 0x138 (cost, flags)
// Names, signatures, and layout are unverified.
// The MIT notice below covers only the names and declarations taken from
// CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; the other code in this file
// is covered by the repository licence and the provenance labels above.
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50, unk58, unk60, unk68, unk70, unk78, unk80, unk88, unk90, unk98, unkA0, unkA8, unkB0, unkB8, unkC0, unkC8, unkD0, unkD8, unkE0, unkE8, unkF0, unkF8, unk100, unk108, unk110, unk118, unk120, unk128, unk130: GUESS(low); storage not read by the compared code
#pragma once
#include <cstdint>
struct AlchemyData {
    std::int32_t  cost;   // 00
    std::uint32_t flags;  // 04
};
class AlchemyItem {
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
    virtual bool Unk_61() const;
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
    virtual AlchemyData* GetData() const;  // 6C
    virtual AlchemyData* GetData2();
    virtual bool IsMedicine() const;
    virtual bool IsPoison() const;
    virtual bool IsFood() const;

    void InitializeData();
    void ClearData();
private:
    void InitializeMagicData();
    void RemoveAllEffects();
    void ClearFormData();
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
    std::uint64_t unk130;  // 130
    int cost;
    std::uint32_t flags;
    void* addictionItem;
    float addictionChance;
    void* consumptionSound;
};
