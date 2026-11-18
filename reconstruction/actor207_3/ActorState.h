// ActorState: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// ActorState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// PlayerReceiver, SetValue, Transition, stateWord, Unknown00: STANDIN GUESS(medium); names and states inferred; omitted virtual identities unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "actors/ActorTargetPrefix.h"
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
    std::uint32_t stateWord;
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
