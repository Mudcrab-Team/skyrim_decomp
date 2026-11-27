// Source exposure: mixed
// Code origin: adapted from the permitted anonymous game-code sibling
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x98b0d0 UI3DSceneManager::SetCameraPosition
// UI3DSceneManager::SetCameraPosition: SIBLING(fo4-private@1b765c70, author-permission)
// Adapted bodies: UI3DSceneManager::SetCameraPosition, fo4-private@1b765c70 src/Game/Interface/UI3DSceneManager.cpp:61, author-permission
#include "UI3DSceneManager_98b0d0.h"

void UI3DSceneManager::SetCameraPosition(const NiPoint3& position)
{
    NiCamera* object = camera;
    if (!object)
        return;
    object->local.translate.x = position.x;
    object->local.translate.y = position.y;
    object->local.translate.z = position.z;
    NiUpdateData data{0.0f, 0};
    object->NiAVObject::Update(data);
}
