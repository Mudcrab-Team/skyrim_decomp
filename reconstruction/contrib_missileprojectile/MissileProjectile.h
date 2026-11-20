// Source exposure: mixed (names and declarations from community headers; the listing of the contributor's own pinned image).
// Code origin: declarations written by hand from the community headers and the local listings; the bodies are in the matching .cpp. The class layout is a minimal stand-in that names only what the compared code touches.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0-or-later.
// MissileProjectile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Projectile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSLoadFormBuffer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declaration only
// ImpactResult, ImpactResult::kNone, ImpactResult::kDestroy: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MissileProjectile::Unk_C2, MissileProjectile::Unk_C3: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); that header declares void, the image returns a bool-sized value
// MissileProjectile::impactResult: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); powerof3 places it at 0x1D8 in SE, this build's listing reads it at 0x1E0
// Projectile::Revert, MissileProjectile::Revert: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared by TESForm at slot 0x12, the image has its own override and calls the Projectile one non-virtually
// Unk_00 through Unk_C1 (except Revert): GUESS(low); placeholder virtual slots that keep Revert at slot 0x12 and Unk_C2 and Unk_C3 at slots 0xC2 and 0xC3
// unk08 through unk1D8: GUESS(low); unexamined 8-byte members of the base that keep impactResult at 0x1E0
#pragma once

#include <cstddef>
#include <cstdint>

class BGSLoadFormBuffer;

enum class ImpactResult : std::int32_t
{
    kNone    = 0,
    kDestroy = 1
};

class Projectile
{
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
    virtual void Revert(BGSLoadFormBuffer* a_buf);  // 12
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
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual void Unk_7D();
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual void Unk_8B();
    virtual void Unk_8C();
    virtual void Unk_8D();
    virtual void Unk_8E();
    virtual void Unk_8F();
    virtual void Unk_90();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void Unk_97();
    virtual void Unk_98();
    virtual void Unk_99();
    virtual void Unk_9A();
    virtual void Unk_9B();
    virtual void Unk_9C();
    virtual void Unk_9D();
    virtual void Unk_9E();
    virtual void Unk_9F();
    virtual void Unk_A0();
    virtual void Unk_A1();
    virtual void Unk_A2();
    virtual void Unk_A3();
    virtual void Unk_A4();
    virtual void Unk_A5();
    virtual void Unk_A6();
    virtual void Unk_A7();
    virtual void Unk_A8();
    virtual void Unk_A9();
    virtual void Unk_AA();
    virtual void Unk_AB();
    virtual void Unk_AC();
    virtual void Unk_AD();
    virtual void Unk_AE();
    virtual void Unk_AF();
    virtual void Unk_B0();
    virtual void Unk_B1();
    virtual void Unk_B2();
    virtual void Unk_B3();
    virtual void Unk_B4();
    virtual void Unk_B5();
    virtual void Unk_B6();
    virtual void Unk_B7();
    virtual void Unk_B8();
    virtual void Unk_B9();
    virtual void Unk_BA();
    virtual void Unk_BB();
    virtual void Unk_BC();
    virtual void Unk_BD();
    virtual void Unk_BE();
    virtual void Unk_BF();
    virtual void Unk_C0();
    virtual void Unk_C1();
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    std::uint64_t unk20;
    std::uint64_t unk28;
    std::uint64_t unk30;
    std::uint64_t unk38;
    std::uint64_t unk40;
    std::uint64_t unk48;
    std::uint64_t unk50;
    std::uint64_t unk58;
    std::uint64_t unk60;
    std::uint64_t unk68;
    std::uint64_t unk70;
    std::uint64_t unk78;
    std::uint64_t unk80;
    std::uint64_t unk88;
    std::uint64_t unk90;
    std::uint64_t unk98;
    std::uint64_t unkA0;
    std::uint64_t unkA8;
    std::uint64_t unkB0;
    std::uint64_t unkB8;
    std::uint64_t unkC0;
    std::uint64_t unkC8;
    std::uint64_t unkD0;
    std::uint64_t unkD8;
    std::uint64_t unkE0;
    std::uint64_t unkE8;
    std::uint64_t unkF0;
    std::uint64_t unkF8;
    std::uint64_t unk100;
    std::uint64_t unk108;
    std::uint64_t unk110;
    std::uint64_t unk118;
    std::uint64_t unk120;
    std::uint64_t unk128;
    std::uint64_t unk130;
    std::uint64_t unk138;
    std::uint64_t unk140;
    std::uint64_t unk148;
    std::uint64_t unk150;
    std::uint64_t unk158;
    std::uint64_t unk160;
    std::uint64_t unk168;
    std::uint64_t unk170;
    std::uint64_t unk178;
    std::uint64_t unk180;
    std::uint64_t unk188;
    std::uint64_t unk190;
    std::uint64_t unk198;
    std::uint64_t unk1A0;
    std::uint64_t unk1A8;
    std::uint64_t unk1B0;
    std::uint64_t unk1B8;
    std::uint64_t unk1C0;
    std::uint64_t unk1C8;
    std::uint64_t unk1D0;
    std::uint64_t unk1D8;
};

class MissileProjectile : public Projectile
{
public:
    void Revert(BGSLoadFormBuffer* a_buf) override;  // compared: 0x7f4e50
    virtual bool Unk_C2();  // C2, compared: 0x7f5660
    virtual bool Unk_C3();  // C3, compared: 0x7f4d60

    ImpactResult impactResult;  // 1E0
};

static_assert(offsetof(MissileProjectile, impactResult) == 0x1E0, "impactResult offset");
