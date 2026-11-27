// Exposure detail: (local target observations; community declarations).
// Source exposure: mixed
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESActorBaseData, TESActorBaseData::GetLevel, ACTOR_BASE_DATA, actorData, actorBaseFlags, level, calcLevelMin, calcLevelMax: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PlayerCharacter, TESNPC: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// playerSingleton, actorBaseData, objectReference, TestBit: GUESS(low); local minimal views and flag helper.

#pragma once
#include <cstdint>
#include <cstddef>
struct ACTOR_BASE_DATA
{
    std::uint32_t actorBaseFlags;
    std::int16_t magickaOffset;
    std::int16_t staminaOffset;
    std::uint16_t level;
    std::uint16_t calcLevelMin;
    std::uint16_t calcLevelMax;
};
class TESActorBaseData
{
public:
    std::uint16_t GetLevel() const;
    void* vtable;
    ACTOR_BASE_DATA actorData;
};
class TESNPC
{
public:
    std::uint8_t unknown00[0x30];
    TESActorBaseData actorBaseData;
};
class PlayerCharacter
{
public:
    std::uint8_t unknown00[0x40];
    TESNPC* objectReference;
};
extern PlayerCharacter* playerSingleton;
inline bool TestBit(std::uint32_t flags, std::uint32_t bit)
{
    return ((flags >> bit) & 1) != 0;
}
static_assert(offsetof(TESActorBaseData, actorData) == 8, "actor data offset");
