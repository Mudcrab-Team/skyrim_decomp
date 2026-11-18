// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// ActorMagicCaster::FinishCastImpl: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActorMagicCaster.cpp:451
// ActorMagicCaster: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/A/ActorMagicCaster.h, include/RE/M/MagicCaster.h, include/RE/R/RefAttachTechniqueInput.h, include/RE/A/AttachTechniqueInput.h and include/RE/S/SimpleAnimationGraphManagerHolder.h.
// names: GUESS(low); actor helper identities and signatures are inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5bf7b0 ActorMagicCaster::FinishCastImpl
#include "ActorMagicCaster_5bf7b0.h"
void ActorMagicCaster::FinishCastImpl() { if (actor) { actor->SetWantCasting(castingSource, false); actor->SetDualCasting(false); } flags &= ~3u; costCharged = 0.0f; }
