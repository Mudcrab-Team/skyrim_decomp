// Source exposure: mixed
// Origin: authorized sibling and community declarations
// ModelReferenceEffect::GetAttachRoot: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:219
// ModelReferenceEffect, ReferenceEffect, RefAttachTechniqueInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/M/ModelReferenceEffect.h, include/RE/R/ReferenceEffect.h, include/RE/R/RefAttachTechniqueInput.h and related base headers
// names: GUESS(low); declarations and signatures remain provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5d7500 ModelReferenceEffect::GetAttachRoot
#include "ModelReferenceEffect.h"
NiAVObject* ModelReferenceEffect::GetAttachRoot() {
    if (hitEffectArtData.attachedArt)
        return hitEffectArtData.attachedArt;
    return ReferenceEffect::GetAttachRoot();
}
