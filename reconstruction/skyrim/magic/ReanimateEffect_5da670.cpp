// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// ReanimateEffect::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReanimateEffect.cpp:69
// ReanimateEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/R/ReanimateEffect.h, include/RE/C/CommandEffect.h, and include/RE/A/ActiveEffect.h.
// names: GUESS(low); helper identity and argument names are inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5da670 ReanimateEffect::SaveGame
#include "ReanimateEffect_5da670.h"
void ReanimateEffect::SaveGame(BGSSaveFormBuffer* buffer) { buffer->Write(&gettingUp, 1, 1, 0); CommandEffect::SaveGame(buffer); }
