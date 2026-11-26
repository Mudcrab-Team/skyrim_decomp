// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x40d7a0 Moon::~Moon
#include "Moon_40d7a0.h"

Moon::~Moon()
{
    shadowMesh = nullptr;
    moonMesh = nullptr;
    shadowNode = nullptr;
    moonNode = nullptr;
    NiNode* parent = root._ptr->parent;
    if (parent)
    {
        parent->DetachChild(root._ptr);
    }
    root = nullptr;
}
