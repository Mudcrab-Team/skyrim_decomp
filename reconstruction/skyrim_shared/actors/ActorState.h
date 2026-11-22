// Source exposure: mixed (pinned image listing and community declarations).
// Code origin: original reconstruction; existing Transition preserved.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// PlayerReceiver, SetValue, Transition, Function6e1ab0, stateWord, stateWord2, Unknown00: STANDIN GUESS(medium); omitted virtual identities unknown.
#pragma once
#include <cstdint>
#include "skyrim_shared/actors/ActorTargetPrefix.h"
namespace P2073 {
class ActorState {
public:
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual bool Transition(std::uint32_t state);
    void Function6e1ab0();
    std::uint32_t stateWord;
    struct StateWord2 {
        std::uint32_t talkingToPlayer : 1;
        std::uint32_t forceRun : 1;
        std::uint32_t forceSneak : 1;
        std::uint32_t headTracking : 1;
        std::uint32_t reanimating : 1;
        std::uint32_t weaponState : 3;
        std::uint32_t wantBlocking : 1;
        std::uint32_t flightBlocked : 1;
        std::uint32_t recoil : 2;
        std::uint32_t allowFlying : 1;
        std::uint32_t staggered : 1;
        std::uint32_t unk14 : 1;
        std::uint32_t unk15 : 17;
    };
    StateWord2 stateWord2;
};
// reference, magicTarget, actorValueOwner, actorState, FromActorState: STANDIN GUESS(medium); represented containing receiver prefix.
class PlayerReceiver {
public:
    P206Target::ReferencePrefix<> reference;
    P206Target::MagicTargetPrefix magicTarget;
    P206Target::InterfacePrefix actorValueOwner;
    ActorState actorState;
    void SetValue(float);
    static PlayerReceiver* FromActorState(ActorState* state) {
        return reinterpret_cast<PlayerReceiver*>(reinterpret_cast<char*>(state) - offsetof(PlayerReceiver, actorState));
    }
};
static_assert(offsetof(PlayerReceiver, actorState) == 0xc0, "target secondary receiver anchor");
}
