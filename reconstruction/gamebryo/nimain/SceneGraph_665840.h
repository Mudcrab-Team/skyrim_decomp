// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SceneGraph, BSSceneGraph: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSSceneGraph: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class BSSceneGraph
{
public:
    BSSceneGraph();
    virtual ~BSSceneGraph();
};

class SceneGraph : public BSSceneGraph
{
public:
    SceneGraph();
    ~SceneGraph() override {}

    char unk08[0x148];
};
static_assert(sizeof(SceneGraph) == 0x150, "SceneGraph size from the deleting destructor");
