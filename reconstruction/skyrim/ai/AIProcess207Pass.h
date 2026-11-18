// AIProcess207Pass: STANDIN GUESS(low); partial target-bound receiver/callee view, no complete layout or ownership asserted.
// Origin: original reconstruction; cited adapted declarations retain complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra. Evidence: findings/ghidra-import.md.
// Partial declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT, AIProcess.h, HighProcessData.h, MiddleHighProcessData.h, InventoryEntryData.h, BSPointerHandle.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "skyrim_shared/actors/ActorValueTargetPrefix.h"
namespace P2071 {
// ObjectRefHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Handle destructor reflects the public nontrivial handle ABI; the value representation and reset behavior are hypotheses for this target.
struct ObjectRefHandle {
    std::uint32_t value;
    ~ObjectRefHandle() { value = 0; }
};
// HighProcessPrefix: STANDIN GUESS(medium); partial target-bound prefix, no full-layout claim.
struct HighProcessPrefix {
    std::uint8_t unknown000[0x140];
    // headTrackTarget, headTracked: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
    ObjectRefHandle headTrackTarget[6];
    bool headTracked[6];
    std::uint8_t unknown15e[0x86];
    // unknown1e4: GUESS(low); target float access only, semantic identity unknown.
    float unknown1e4;
};
// InventoryFormPrefix, InventoryEntryPrefix, MiddleHighPrefix: STANDIN GUESS(medium); partial representations, no pointer ownership claimed.
struct InventoryFormPrefix { P206Target::FormPrefix form; };
struct InventoryEntryPrefix { InventoryFormPrefix* object; };
struct MiddleHighPrefix {
    std::uint8_t unknown000[0x220];
    // leftHand, rightHand: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
    InventoryEntryPrefix* leftHand;
    std::uint8_t unknown228[0x38];
    InventoryEntryPrefix* rightHand;
};
// AIProcess207Pass: STANDIN GUESS(medium); target process prefix and receiver, allocation extent not asserted.
struct AIProcess207Pass {
    P206Target::MiddleLowProcessData* middleLow;
    MiddleHighPrefix* middleHigh;
    HighProcessPrefix* high;
    P206Target::ActorPackage currentPackage;
    float unknown48;
    std::uint32_t unknown4c;
    // GetHeadtrackTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
    ObjectRefHandle GetHeadtrackTarget() const;
    // SetHighFloat, UpdateTimeBits, GetWeaponEntry: GUESS(low); semantic identities and parameter names inferred.
    void SetHighFloat(float);
    void UpdateTimeBits();
    InventoryEntryPrefix* GetWeaponEntry(bool);
};
// InvalidHandle, TimeFloat, TimeHigh, TimeLow, TimeMiddle: GUESS(low); external values and semantics unconfirmed.
extern std::uint32_t InvalidHandle, TimeHigh, TimeMiddle;
extern std::int8_t TimeLow;
extern float TimeFloat;
static_assert(offsetof(AIProcess207Pass, high)==0x10, "target high pointer");
static_assert(offsetof(AIProcess207Pass, unknown48)==0x48, "target time float");
static_assert(offsetof(AIProcess207Pass, unknown4c)==0x4c, "target time bits");
static_assert(offsetof(HighProcessPrefix, headTrackTarget)==0x140, "target head handles");
static_assert(offsetof(HighProcessPrefix, headTracked)==0x158, "target head flags");
static_assert(offsetof(HighProcessPrefix, unknown1e4)==0x1e4, "target float");
static_assert(offsetof(MiddleHighPrefix, leftHand)==0x220, "target left entry");
static_assert(offsetof(MiddleHighPrefix, rightHand)==0x260, "target right entry");
}
