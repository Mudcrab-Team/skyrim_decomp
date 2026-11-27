// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations
// 0x150c000 ShadowSceneNode::~ShadowSceneNode
#include "ShadowSceneNode_R5A6.h"

// ~ShadowSceneNode: CRASHLOGGER_PDB(59818@2026.10.24)
ShadowSceneNode::~ShadowSceneNode()
{
    if (g_shaderManagerState.shadowSceneNode[sceneGraphIndex] == this) {
        SetShadowSceneNode(sceneGraphIndex, nullptr);
    }
    ClearLightArrays();
    delete sunLight;
    delete shadowDirLight;
    queuedAdd.Clear(true);
    queuedRemove.Clear(true);
    lightQueueRemove.Clear(true);
    portalGraph = nullptr;
}
