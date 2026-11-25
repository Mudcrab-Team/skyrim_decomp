// Near miss: 75.58% | inline-set
// Exposure detail: (community declarations and local binary analysis).
// Source exposure: mixed
// Code origin: original hand-written reconstruction; community declarations and permitted sibling method names.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Inventory3DManager, LoadedInventoryModel, NiAVObject, NiMatrix3, NiTransform, NiPoint3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// loadedModels, spModel, entry, local, world, rotate, translate, scale, x, y, z, loadTask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// modelCapacity, loadedModelCount, modelStorage, unused: GUESS(low); partial array layout observed locally
// Inventory3DManager::GetModelRotation: SIBLING(fo4-private@1b765c70, author-permission)
// 0x93e3d0 Inventory3DManager::GetModelRotation

#include "include/93e3d0/Inventory3DManager_93e3d0.h"

// identityRotation: GUESS(low); fallback matrix stored in the pinned image
extern const NiMatrix3 identityRotation;

NiMatrix3 Inventory3DManager::GetModelRotation() const
{
    const NiMatrix3* rotation;
    if (loadTask == nullptr && loadedModelCount != 0) {
        const auto* models = static_cast<std::int32_t>(modelCapacity) < 0 ? modelStorage.inlineModels : modelStorage.externalModels;
        rotation = &models[loadedModelCount - 1].spModel->world.rotate;
    } else {
        rotation = &identityRotation;
    }
    return *rotation;
}
