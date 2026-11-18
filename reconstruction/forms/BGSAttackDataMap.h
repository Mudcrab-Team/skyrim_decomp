// Code origin: hand-written class layout and declarations adapted from the CharmedBaryon/CommonLibSSE-NG headers named below; the compared body is written from the local listing.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAttackDataMap, BGSAttackDataMap::GetAttackData, BGSAttackDataMap::~BGSAttackDataMap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTHashMap, BGSAttackData, BSFixedString, TESRace, BGSAttackDataMap::attackDataMap, BGSAttackDataMap::defaultDataRace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTHashMap::_pad00, BSTHashMap::_pad08, BSTHashMap::_capacity, BSTHashMap::_free, BSTHashMap::_good, BSTHashMap::_sentinel, BSTHashMap::_allocator, BSTHashMap::_entries: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); BSTScatterTable and its allocator flattened, non-template
// BGSAttackDataMap::GetAttackData parameters and result: GUESS(low); the body only forwards its arguments
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiRefObject.h"

class BGSAttackData;
class BSFixedString;
class TESRace;

// Non-template stand-in for BSTHashMap<BSFixedString, NiPointer<BGSAttackData>> with the community layout.
struct BSTHashMapAttackData
{
    std::uint64_t pad00;  // 00
    std::uint32_t pad08;  // 08
    std::uint32_t capacity;  // 0C
    std::uint32_t free;  // 10
    std::uint32_t good;  // 14
    const void* sentinel;  // 18
    std::uint64_t allocatorPad00;  // 20
    void* entries;  // 28
};
static_assert(sizeof(BSTHashMapAttackData) == 0x30, "BSTHashMapAttackData size");

class BGSAttackDataMap : public NiRefObject
{
public:
    ~BGSAttackDataMap() override;  // 00
    BGSAttackData* GetAttackData(const BSFixedString& a_event);  // compared: 0x44ab10

    BSTHashMapAttackData attackDataMap;  // 10
    TESRace* defaultDataRace;  // 40
};
static_assert(sizeof(BGSAttackDataMap) == 0x48, "BGSAttackDataMap size");
static_assert(offsetof(BGSAttackDataMap, attackDataMap) == 0x10, "BGSAttackDataMap members");
