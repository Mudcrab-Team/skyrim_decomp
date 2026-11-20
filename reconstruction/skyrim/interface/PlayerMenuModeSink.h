// PlayerMenuModeSink: STANDIN GUESS(low); partial target view; original identities and ownership remain hypotheses.
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// MenuModeChangeEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// PlayerMenuModeSink, ProcessEvent, PlayerReceiver, NotifyMode, mode, currentMode: STANDIN GUESS(medium); event receiver bound at offset 0x2c0, remaining identities inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "skyrim_shared/actors/ActorPrimaryTargetPrefix.h"
namespace P2073 {
struct MenuModeChangeEvent { const void* menu; std::uint8_t mode; };
extern std::int32_t currentMode;
class PlayerMenuModeSink : public P206Target::InterfacePrefix {
public:
    std::int32_t ProcessEvent(const MenuModeChangeEvent* event, void* source);
};
// PlayerReceiver: STANDIN GUESS(medium); containing prefix adapted from the cited Actor and PlayerCharacter declarations.
// Source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT; include/RE/A/Actor.h and include/RE/P/PlayerCharacter.h.
// The intermediate fields are public hypotheses; only the menu-mode receiver anchor is target-bound here.
// Modifiers, NativeCriticalSection, FromMenuModeSink: STANDIN GUESS(medium); storage views of named modifier and synchronization state.
// actor, exclusiveBranch, healthModifiers, magickaModifiers, staminaModifiers, voicePointsModifiers, lastUpdate, lastSeenTime, biped, armorRating, armorBaseFactorSum, soundCallBackSet, menuOpenCloseSink, menuModeSink: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// unknown271, unknown272, unknown273, unknown274, unknown278, unknown280, debugInfo, lockCount, recursionCount, owningThread, lockSemaphore, spinCount: STANDIN GUESS(low); unknown scalar and native synchronization field identities.
class PlayerReceiver {
public:
    struct Modifiers { float permanent; float temporary; float damage; };
    struct NativeCriticalSection {
        void* debugInfo;
        std::int32_t lockCount;
        std::int32_t recursionCount;
        void* owningThread;
        void* lockSemaphore;
        std::uintptr_t spinCount;
    };
    P206Target::ActorPrimaryTargetPrefix actor;
    void* exclusiveBranch;
    Modifiers healthModifiers;
    Modifiers magickaModifiers;
    Modifiers staminaModifiers;
    Modifiers voicePointsModifiers;
    float lastUpdate;
    std::uint32_t lastSeenTime;
    void* biped;
    float armorRating;
    float armorBaseFactorSum;
    std::int8_t soundCallBackSet;
    std::uint8_t unknown271;
    std::uint8_t unknown272;
    std::uint8_t unknown273;
    std::uint32_t unknown274;
    std::uint64_t unknown278;
    std::uint64_t unknown280;
    NativeCriticalSection synchronization;
    P206Target::InterfacePrefix menuOpenCloseSink;
    PlayerMenuModeSink menuModeSink;
    void NotifyMode(bool);
    static PlayerReceiver* FromMenuModeSink(PlayerMenuModeSink* sink) {
        return reinterpret_cast<PlayerReceiver*>(reinterpret_cast<char*>(sink) - offsetof(PlayerReceiver, menuModeSink));
    }
};
static_assert(offsetof(PlayerReceiver, menuModeSink) == 0x2c0, "target menu-mode receiver anchor");
}
