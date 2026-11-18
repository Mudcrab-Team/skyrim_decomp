// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// ActorMagicCaster::GetCasterAsActor: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActorMagicCaster.cpp:463
// ActorMagicCaster, MagicCaster, SimpleAnimationGraphManagerHolder, RefAttachTechniqueInput: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/A/ActorMagicCaster.h, include/RE/M/MagicCaster.h, include/RE/S/SimpleAnimationGraphManagerHolder.h and include/RE/R/RefAttachTechniqueInput.h.
// BSTArrayHeapAllocator, BSTArrayBase: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/B/BSTArray.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5c2cb0 ActorMagicCaster::GetCasterAsActor
#include "ActorMagicCaster.h"
Actor* ActorMagicCaster::GetCasterAsActor() const { return actor; }
