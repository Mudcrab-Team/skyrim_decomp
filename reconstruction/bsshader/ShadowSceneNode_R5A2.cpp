// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations
// 0x150e040 ProcessAllQueuedLights
// CI hash: 0x150e040 ?ProcessAllQueuedLights@@YAXPEAVBSGeometryListCullingProcess@@@Z
#include "ShadowSceneNode_R5A2.h"

// ProcessAllQueuedLights: CRASHLOGGER_PDB(59818@2026.10.24)
void ProcessAllQueuedLights(BSGeometryListCullingProcess* a_process)
{
    for (std::uint32_t i = 0; i < 4; ++i) {
        ShadowSceneNode* node = g_shaderManagerState.shadowSceneNode[i];
        if (node) {
            node->ProcessQueuedLights(a_process);
        }
    }
}
