// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FaceGen/BSFaceGenManager.cpp:460
// BSFaceGenManager, BSFaceGenManager::ApplyCharGenMorphToHead: SIBLING(fo4-private@1b765c70, author-permission)
// TESNPC::ForEachHeadPart: GUESS(medium); name from the sibling call site, stand-in template
// TESNPC: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFaceGenNiNode, BGSHeadPart, BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declarations only
#pragma once

#include <cstdint>
#include <cstddef>

class BSFaceGenNiNode;
class BGSHeadPart;
class BSFixedString;

class TESNPC
{
public:
    template <class Visitor>
    void ForEachHeadPart(Visitor& a_visitor) const;
};

class BSFaceGenManager
{
public:
    void ApplyCharGenMorphToHead(BSFaceGenNiNode* a_headNode, const TESNPC* a_npc, const BSFixedString& a_morphName, float a_modifierValue);
};
