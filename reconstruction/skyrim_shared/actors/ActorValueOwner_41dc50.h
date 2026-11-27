// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorValueOwner, ActorValueOwner::sub_1403BD3C0: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorValueOwner::GetPermanentActorValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Data41dc50, Mult41dc50, g_defaultMult41dc50, TestBit, ActorValueOwner::Unk_01: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern float g_defaultMult41dc50;

struct Data41dc50
{
    std::uint8_t  unk00[0x38];
    std::uint32_t flags;  // 0x38
    std::uint8_t  unk3c[0x12];
    std::int16_t  unk4e;  // 0x4e
};
static_assert(offsetof(Data41dc50, flags) == 0x38, "Data41dc50::flags offset");
static_assert(offsetof(Data41dc50, unk4e) == 0x4e, "Data41dc50::unk4e offset");

struct Mult41dc50
{
    std::uint8_t unk00[0x68];
    float        unk68;  // 0x68
};
static_assert(offsetof(Mult41dc50, unk68) == 0x68, "Mult41dc50::unk68 offset");

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1u) != 0;
}

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float Unk_01(std::int32_t a_av) const;
    virtual float GetPermanentActorValue(std::int32_t a_av) const;  // 0x02 (0x10)

    float sub_1403BD3C0(const Data41dc50* a_data, const Mult41dc50* a_mult) const;
};
