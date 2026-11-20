// ActorValueTargetPrefix: STANDIN GUESS(medium); partial target-bound view, not an original complete declaration.
// Origin: original declarations adapted from pinned community headers.
// Source exposure: mixed (independent target accesses and public type hypotheses).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "ActorTargetPrefix.h"
namespace P206Target {
// TESPackage, CombatController, TESFaction, SpellItem, ActorMagicCaster, MagicItem, TESRace, ActorValueStorage, Modifiers: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class TESPackage; class CombatController; class TESFaction; class SpellItem; class ActorMagicCaster; class MagicItem; class TESRace;
// SmallSpellArray, ActorValueMap: STANDIN GUESS(medium); storage-only adaptations of BSTSmallArray and ActorValueStorage::LocalMap.
struct SmallSpellArray {
    std::uint32_t capacityAndLocal;
    std::uint32_t pad04;
    union { SpellItem** heap; SpellItem* local[1]; } data;
    std::uint32_t size;
    std::uint32_t pad14;
};
struct Modifiers { float modifiers[3]; };
template<class T> struct ActorValueMap { const char* actorValues; T* entries; };
struct ActorValueStorage {
    ActorValueMap<float> baseValues;
    ActorValueMap<Modifiers> modifiers;
    // Clear: GUESS(medium); target callee at RVA 0x6e3430; does not imply allocation ownership.
    void Clear();
};
// unk150, combatController, vendorFaction, calculateVendorFactionTimer, emotionType, emotionValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// intimidateBribeDayStamp, addedSpells, magicCasters, selectedSpells, selectedPower, race, equippedWeight, boolFlags, avStorage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
template<class Process = AIProcess>
struct ActorValueTargetPrefix : public ActorTargetPrefix<ExtraDataListPrefix, Process> {
    TESPackage* unk150;
    CombatController* combatController;
    TESFaction* vendorFaction;
    float calculateVendorFactionTimer;
    std::uint32_t emotionType;
    std::uint32_t emotionValue;
    std::uint32_t unknown17C;
    std::uint32_t unknown180;
    std::uint32_t intimidateBribeDayStamp;
    std::uint64_t unknown188;
    SmallSpellArray addedSpells;
    ActorMagicCaster* magicCasters[4];
    MagicItem* selectedSpells[4];
    TESForm* selectedPower;
    std::uint32_t unknown1F0;
    std::uint32_t pad1F4;
    TESRace* race;
    float equippedWeight;
    std::uint32_t boolFlags;
    ActorValueStorage avStorage;
};
static_assert(sizeof(SmallSpellArray) == 0x18, "public array storage representation only");
static_assert(sizeof(ActorValueStorage) == 0x20, "represented value-map pair");
static_assert(offsetof(ActorValueTargetPrefix<>, selectedSpells) == 0x1c8, "target indexed spell access at RVA 0x6d6d00");
static_assert(offsetof(ActorValueTargetPrefix<>, avStorage) == 0x208, "target value-storage receiver at RVA 0x6c57f0");
// ActorPackage, MiddleLowProcessData, MiddleHighProcessData, HighProcessData, ActorPackageData, CachedValues: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class MiddleLowProcessData; class MiddleHighProcessData; class HighProcessData; class ActorPackageData;
struct ActorPackage {
    std::uint32_t lockThread, lockCount;
    TESPackage* package;
    ActorPackageData* data;
    ObjectRefHandle target;
    std::int32_t currentProcedureIndex;
    float packageStartTime;
    std::uint32_t modifiedPackageFlag;
    std::uint16_t modifiedInterruptFlag;
    std::int8_t actorPackageFlags;
    std::int8_t preferredSpeed;
    std::uint32_t pad2C;
};
struct CachedValues {
    float cachedRadius, cachedWidth, cachedLength, cachedForwardLength;
    float cachedDPS, cachedEyeLevel, cachedWalkSpeed, cachedRunSpeed, cachedJogSpeed, cachedFastWalkSpeed;
    std::uint32_t booleanValues;
    std::uint32_t flags;
};
// AIProcessTargetPrefix: STANDIN GUESS(medium); process prefix through the target cachedValues access.
struct AIProcessTargetPrefix {
    MiddleLowProcessData* middleLow;
    MiddleHighProcessData* middleHigh;
    HighProcessData* high;
    ActorPackage currentPackage;
    float unknown48;
    std::uint32_t unknown4C;
    CachedValues* cachedValues;
    // ResetCache: GUESS(low); direct target callee at RVA 0x6eaf40, original name unknown.
    void ResetCache();
};
static_assert(offsetof(AIProcessTargetPrefix, cachedValues) == 0x50, "target cache-pointer access at RVA 0x6a7c90");
static_assert(offsetof(CachedValues, cachedWalkSpeed) == 0x18, "target cached-speed store");
static_assert(offsetof(CachedValues, flags) == 0x2c, "target cache flag access");
}
