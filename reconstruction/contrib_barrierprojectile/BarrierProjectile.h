// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: declarations written by hand from the community headers and the local listings; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7df6b0 BarrierProjectile::SaveGame
// 0x7df700 BarrierProjectile::LoadGame
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

    std::uint64_t pad08;
    std::uint64_t pad10;
    std::uint64_t pad18;
    std::uint64_t pad20;
    std::uint64_t pad28;
    std::uint64_t pad30;
    std::uint64_t pad38;
    std::uint64_t pad40;
    std::uint64_t pad48;
    std::uint64_t pad50;
    std::uint64_t pad58;
    std::uint64_t pad60;
    std::uint64_t pad68;
    std::uint64_t pad70;
    std::uint64_t pad78;
    std::uint64_t pad80;
    std::uint64_t pad88;
    std::uint64_t pad90;
    std::uint64_t pad98;
    std::uint64_t padA0;
    std::uint64_t padA8;
    std::uint64_t padB0;
    std::uint64_t padB8;
    std::uint64_t padC0;
    std::uint64_t padC8;
    std::uint64_t padD0;
    std::uint64_t padD8;
    std::uint64_t padE0;
    std::uint64_t padE8;
    std::uint64_t padF0;
    std::uint64_t padF8;
    std::uint64_t pad100;
    std::uint64_t pad108;
    std::uint64_t pad110;
    std::uint64_t pad118;
    std::uint64_t pad120;
    std::uint64_t pad128;
    std::uint64_t pad130;
    std::uint64_t pad138;
    std::uint64_t pad140;
    std::uint64_t pad148;
    std::uint64_t pad150;
    std::uint64_t pad158;
    std::uint64_t pad160;
    std::uint64_t pad168;
    std::uint64_t pad170;
    std::uint64_t pad178;
    std::uint64_t pad180;
    std::uint64_t pad188;
    std::uint64_t pad190;
    std::uint64_t pad198;
    std::uint64_t pad1A0;
    std::uint64_t pad1A8;
    std::uint64_t pad1B0;
    std::uint64_t pad1B8;
    std::uint64_t pad1C0;
    std::uint64_t pad1C8;
    std::uint64_t pad1D0;
    std::uint64_t pad1D8;
};

class BarrierProjectile : public Projectile
{
public:
    void SaveGame(BGSSaveFormBuffer* a_buf) override;  // compared: 0x7df6b0
    void LoadGame(BGSLoadFormBuffer* a_buf) override;  // compared: 0x7df700

    std::uint32_t unk1E0;  // 1E0
};

static_assert(offsetof(BarrierProjectile, unk1E0) == 0x1E0, "unk1E0 offset");
