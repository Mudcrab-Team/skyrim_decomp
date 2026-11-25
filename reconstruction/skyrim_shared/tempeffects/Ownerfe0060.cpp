// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x5d74e0 (skyrim_shared/tempeffects/ModelReferenceEffect_5d74e0): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// Origin: authorized sibling and community declarations
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:212
// ReferenceEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/M/ModelReferenceEffect.h, include/RE/R/ReferenceEffect.h, include/RE/R/RefAttachTechniqueInput.h and related base headers
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfe0060 Ownerfe0060::UpdateParentCell
#include "Ownerfe0060.h"

// guess: same compiled code as matched 0x5d74e0 apart from relocated fields; its role here is not established.
void Ownerfe0060::UpdateParentCell(NiAVObject* root) {
    if (!(flags & 1))
        ReferenceEffect::UpdateParentCell(root);
}
