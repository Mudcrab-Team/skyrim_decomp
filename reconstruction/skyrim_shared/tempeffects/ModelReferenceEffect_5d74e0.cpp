// Source exposure: mixed
// Origin: authorized sibling and community declarations
// ModelReferenceEffect::UpdateParentCell: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:212
// ModelReferenceEffect, ReferenceEffect, RefAttachTechniqueInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/M/ModelReferenceEffect.h, include/RE/R/ReferenceEffect.h, include/RE/R/RefAttachTechniqueInput.h and related base headers
// names: GUESS(low); declarations and signatures remain provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5d74e0 ModelReferenceEffect::UpdateParentCell
#include "ModelReferenceEffect_5d74e0.h"
void ModelReferenceEffect::UpdateParentCell(NiAVObject* root) {
    if (!(flags & 1))
        ReferenceEffect::UpdateParentCell(root);
}
