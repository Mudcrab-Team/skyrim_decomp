// Near miss: 70.31% | inline-set
// Exposure detail: (community declarations and local binary analysis).
// Source exposure: mixed
// Code origin: original hand-written reconstruction; community declarations and permitted sibling method names.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Inventory3DManager, LoadedInventoryModel, NiAVObject, NiMatrix3, NiTransform, NiPoint3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// loadedModels, spModel, entry, local, world, rotate, translate, scale, x, y, z, loadTask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// modelCapacity, loadedModelCount, modelStorage, unused: GUESS(low); partial array layout observed locally
// Inventory3DManager::GetModelScale: SIBLING(fo4-private@1b765c70, author-permission)
// 0x93e430 Inventory3DManager::GetModelScale

#include "include/93e430/Inventory3DManager_93e430.h"

float Inventory3DManager::GetModelScale() const
{
    if (loadTask == nullptr && loadedModelCount != 0) {
        const auto* models = static_cast<std::int32_t>(modelCapacity) < 0 ? modelStorage.inlineModels : modelStorage.externalModels;
        return models[loadedModelCount - 1].spModel->local.scale;
    }
    return 1.0f;
}
