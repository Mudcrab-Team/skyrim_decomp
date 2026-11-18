// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// Actor::SetRestrained: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:2720
// Actor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/A/Actor.h, ActorState.h, ActorValueOwner.h, ActorMagicCaster.h, include/RE/M/MagicCaster.h and the base declarations in reconstruction/fo4b4c_686600/Actor.h.
// Base declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/A/Actor.h, ActorState.h, ActorValueOwner.h, RE/T/TESObjectREFR.h, TESForm.h, RE/E/ExtraDataList.h, RE/M/MagicTarget.h, RE/B/BSHandleRefObject.h, BSAtomic.h, BSTEvent.h, RE/T/TESNPC.h, TESActorBase.h, TESActorBaseData.h, TESContainer.h, TESSpellList.h, TESAIForm.h, TESFullName.h, TESRaceForm.h, RE/B/BGSKeywordForm.h, BGSAttackDataForm.h, BGSPerkRankArray.h, BGSSkinForm.h, BGSDestructibleObjectForm.h and RE/I/IAnimationGraphManagerHolder.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x687b40 Actor::SetRestrained
#include "Actor.h"
void Actor::SetRestrained(bool value) { if (value) { SetLifeState(6); StopMoving(1.0f); } else if ((actorState1 & 0x1e00000) == 0xc00000) SetLifeState(0); }
