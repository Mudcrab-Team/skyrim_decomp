// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x5d74e0 (skyrim_shared/tempeffects/ModelReferenceEffect_5d74e0): source copied, names replaced by placeholders.
// Origin: authorized sibling and community declarations
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:212
// ReferenceEffect, RefAttachTechniqueInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/M/ModelReferenceEffect.h, include/RE/R/ReferenceEffect.h, include/RE/R/RefAttachTechniqueInput.h and related base headers
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Ownerfe0060: GUESS(low) STANDIN
#pragma once
#include "ModelReferenceEffect_5d74e0.h"

class Ownerfe0060 : public ReferenceEffect, public SimpleAnimationGraphManagerHolder, public AnimationGraphEventSink {
public:
    void UpdateParentCell(NiAVObject*) override;
    RefAttachTechniqueInput hitEffectArtData;
    char* loadGameSubBuffer;
    BGSArtObject* artObject;
    BGSArtObjectCloneTask* cloneTask;
    NiAVObject* artObject3D;
    unsigned char padTwinD0[36];
    std::uint32_t flags;
};
