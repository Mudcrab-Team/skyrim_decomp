// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4329a0 BSFaceGenManager::ApplyCharGenMorphToHead
// Adapted bodies: BSFaceGenManager::ApplyCharGenMorphToHead from fo4-private@1b765c70 src/Shared/FaceGen/BSFaceGenManager.cpp:460 (see the header)
#include "BSFaceGenManager_4329a0.h"

void BSFaceGenManager::ApplyCharGenMorphToHead(BSFaceGenNiNode* a_headNode, const TESNPC* a_npc, const BSFixedString& a_morphName, float a_modifierValue)
{
    struct ApplyCharGenMorphFunctor
    {
        BSFaceGenNiNode* headNode;
        const TESNPC* npc;
        const BSFixedString* morphName;
        float modifierValue;

        void operator()(BGSHeadPart*) const
        {
        }
    };

    ApplyCharGenMorphFunctor applyCharGenMorph;
    applyCharGenMorph.headNode = a_headNode;
    applyCharGenMorph.npc = a_npc;
    applyCharGenMorph.morphName = &a_morphName;
    applyCharGenMorph.modifierValue = a_modifierValue;

    a_npc->ForEachHeadPart(applyCharGenMorph);
}
