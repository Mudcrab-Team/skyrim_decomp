// ComplexPass: STANDIN GUESS(low); ordinary receiver identity is provisional.
// Source exposure: mixed (binary-analysis and community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction; community declarations adapted as noted.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "skyrim_shared/actors/ActorTargetPrefix.h"
namespace P206Target { class ActorMover { public: virtual ~ActorMover(); }; }
namespace P2061 {
// ComplexPass, ActorVtable, CombatGroup: STANDIN GUESS(low); object and interface identity is provisional.
// ActorMover: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); target owner and destruction semantics require review.
class ComplexPass; struct Item; struct CombatGroup { bool Contains(ComplexPass*); };
struct ActorVtable {
 void* unknown000[90]; void (*AddObject)(ComplexPass*,Item*,void*,int,void*);
 void* unknown091[121]; CombatGroup* (*GetCombatGroup)(ComplexPass*);
 void* unknown213[14]; bool (*IsInCombat)(ComplexPass*);
};
class ComplexPass : public P206Target::ActorTargetPrefix<> {
public:
 // UpdateCombatControllerSettings, DestroyActorMover: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); target primary slots 283 and 293.
 // Func261, IsCombatTarget, UpdateSettings: GUESS(low); names or signature remain provisional.
 void UpdateCombatControllerSettings(); void DestroyActorMover(); void Func261(Item*); bool IsCombatTarget(ComplexPass*); void UpdateSettings();
};
}
