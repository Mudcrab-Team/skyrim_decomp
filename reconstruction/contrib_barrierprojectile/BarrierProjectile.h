// Source exposure: mixed (names and declarations from community headers; the listing of the contributor's own pinned image).
// Code origin: declarations written by hand from the community headers and the local listings; the bodies are in the matching .cpp. The class layout is a minimal stand-in that names only what the compared code touches.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BarrierProjectile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Projectile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BarrierProjectile::SaveGame, BarrierProjectile::LoadGame, Projectile::SaveGame, Projectile::LoadGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared by TESForm at slots 0x0E and 0x0F, the image has its own override and calls the Projectile one non-virtually
// BGSSaveGameBuffer, BGSSaveFormBuffer, BGSSaveGameBuffer::SaveDataEndian, BGSLoadGameBuffer, BGSLoadFormBuffer, BGSLoadGameBuffer::LoadDataEndian: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; only the two calls the compared code makes are declared, with the argument lists the image passes
// BarrierProjectile::unk1E0: GUESS(low); the four-byte value the compared code saves and loads
// Unk_00 through Unk_0D: GUESS(low); placeholder virtual slots that keep SaveGame and LoadGame at slots 0x0E and 0x0F
// pad08 through pad1D8: GUESS(low); unexamined 8-byte members of the base that keep unk1E0 at 0x1E0
#pragma once

#include <cstddef>
#include <cstdint>

class BGSSaveGameBuffer
{
public:
    void SaveDataEndian(const void* a_data, std::uint32_t a_size, std::uint32_t a_count, std::uint32_t a_arg4);
};

class BGSSaveFormBuffer : public BGSSaveGameBuffer
{
};

class BGSLoadGameBuffer
{
public:
    void LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size);
};

class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
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
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);  // 0E
    virtual void LoadGame(BGSLoadFormBuffer* a_buf);  // 0F

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

class BarrierProjectile : public Projectile
{
public:
    void SaveGame(BGSSaveFormBuffer* a_buf) override;  // compared: 0x7df6b0
    void LoadGame(BGSLoadFormBuffer* a_buf) override;  // compared: 0x7df700

    std::uint32_t unk1E0;  // 1E0
};

static_assert(offsetof(BarrierProjectile, unk1E0) == 0x1E0, "unk1E0 offset");
