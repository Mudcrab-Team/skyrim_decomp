// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations
// 0x1510940 ShadowSceneNode::BuildSharedCompoundFrustum
#include "ShadowSceneNode_R5A5.h"

// BuildSharedCompoundFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
BSCompoundFrustum* ShadowSceneNode::BuildSharedCompoundFrustum(BSCullingProcess* a_process, BSPortal* a_portal)
{
    MemoryContextScope scope(0x20);
    NiCamera* camera = a_process->camera;
    BSCompoundFrustumCache* cache = a_process->unk30190;
    BSCompoundFrustum* frustum = cache->Find(a_portal->portalSharedNode);
    if (frustum) {
        frustum->SetCamera(a_process->camera);
    } else {
        frustum = BSCompoundFrustum::Create();
        frustum->SetCamera(a_process->camera);
        cache->Insert(a_portal->portalSharedNode, frustum);
    }

    BSMultiBoundRoom* entranceRoom = a_portal->entranceRoom;
    BSMultiBoundRoom* exitRoom = a_portal->exitRoom;
    BSCompoundFrustum* entranceFrustum = entranceRoom ? cache->Find(entranceRoom) : &cache->openFrustum;
    BSCompoundFrustum* exitFrustum = &cache->openFrustum;
    if (exitRoom) {
        exitFrustum = cache->Find(exitRoom);
    }
    bool entranceKnown = entranceRoom ? entranceFrustum != nullptr : cache->openAllowed;
    bool exitKnown = exitRoom ? exitFrustum != nullptr : cache->openAllowed;
    bool useEntrance = entranceRoom ? (entranceKnown && entranceFrustum->freeOp != 0) : cache->openFrustum.freeOp == 0;
    bool useExit = exitRoom ? (exitKnown && exitFrustum->freeOp != 0) : cache->openFrustum.freeOp == 0;

    frustum->SetCamera(camera);
    if (entranceKnown && entranceFrustum->freeOp == 0) {
        return frustum;
    }
    if (exitKnown && exitFrustum->freeOp == 0) {
        return frustum;
    }
    if (useEntrance) {
        if (!useExit) {
            frustum->AddFrustum(entranceFrustum);
        } else {
            frustum->BeginOperators();
            frustum->AddFrustum(entranceFrustum);
            frustum->AddFrustum(exitFrustum);
            frustum->EndOperators();
        }
    } else if (useExit) {
        frustum->AddFrustum(exitFrustum);
    }
    frustum->BuildPlanes();
    frustum->BuildOperators();
    return frustum;
}
