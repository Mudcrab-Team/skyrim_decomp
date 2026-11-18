// PlayerCharacterTargetMembers: STANDIN GUESS(medium); partial target-bound view, not an original complete declaration.
// Origin: original declarations adapted from pinned community headers.
// Source exposure: mixed (independent target accesses and public type hypotheses).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "ActorTargetInterfaces.h"
namespace P206Target {
// ImageSpaceModifierInstanceDOF, PlayerSkills, CombatGroup, NiNode, BipedAnim: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ImageSpaceModifierInstanceDOF; class PlayerSkills; class CombatGroup; class NiNode;
// PointerStorage, MemberBinding: STANDIN GUESS(medium); typed non-owning representations with independent target offsets.
template<class T> struct PointerStorage { T* value; };
template<class Owner, class Member, std::uint32_t Offset>
struct MemberBinding { using Receiver=Owner; using Type=Member; enum : std::uint32_t { offset=Offset }; };
// These windows start at their named target offsets; no preceding storage or complete size is fabricated.
// DepthOfFieldWindow, FirstPersonWindow, PlayerFlagWindow: STANDIN GUESS(medium); window names invented.
// vatsDOFInstance, dynamicDOFInstance, largeBiped, firstPerson3D, playerFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
struct DepthOfFieldWindow { ImageSpaceModifierInstanceDOF* vatsDOFInstance; ImageSpaceModifierInstanceDOF* dynamicDOFInstance; };
struct FirstPersonWindow { PointerStorage<BipedAnim> largeBiped; PointerStorage<NiNode> firstPerson3D; };
struct PlayerFlagWindow { std::uint8_t playerFlags; };
class PlayerCharacterTargetMembers {
public:
    // DepthOfField: GUESS(medium); two pointer accesses at RVAs 0x778b30 and 0x778b70; cleanup calls establish no ownership policy
    using DepthOfField=MemberBinding<PlayerReceiver,DepthOfFieldWindow,0x6f0>;
    // FirstPerson: GUESS(medium); target address/reference paths at RVAs 0x748c50 and 0x747af0
    using FirstPerson=MemberBinding<PlayerReceiver,FirstPersonWindow,0x8f8>;
    // Skills: GUESS(medium); target pointer/callee contract at RVA 0x7499e0
    using Skills=MemberBinding<PlayerReceiver,PlayerSkills*,0x9c0>;
    // Combat: GUESS(medium); target pointer/receiver contract at RVA 0x776a40
    using Combat=MemberBinding<PlayerReceiver,CombatGroup*,0x9e0>;
    // Flags: GUESS(medium); target bit-five store at RVA 0x749070
    using Flags=MemberBinding<PlayerReceiver,PlayerFlagWindow,0xbe8>;
};
// PlayerSkillsCallee, CombatGroupCallee: STANDIN GUESS(medium); explicit-receiver target callee hypotheses, not original names.
// The skill callee consumes six arguments after its receiver, including both boolean stack arguments.
using PlayerSkillsCallee=void (*)(PlayerSkills*,ActorValue,float,TESForm*,std::int32_t,bool,bool);
using CombatGroupCallee=void (*)(CombatGroup*,ActorReceiver*);
}
