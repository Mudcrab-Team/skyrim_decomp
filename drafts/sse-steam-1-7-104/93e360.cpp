// Near miss: 76.92% | inline-set
// Exposure detail: (local target analysis and community declarations).
// Source exposure: mixed
// Code origin: original reconstruction from target observations and attributed community material.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Inventory3DManager, LoadedInventoryModel, itemBase, modelObj, spModel, loadTask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations and name hints.
// GetLastModelPosition, InventoryModelPosition, InventoryLoadedObject, position, modelCapacity, models, loadedModelCount, inventoryDefaultPosition, unknown ranges: GUESS(low); target-accessed fields inferred locally.
// 0x93e360 Inventory3DManager::GetLastModelPosition

#include "include/93e360/Inventory3DManager_93e360.h"

// Guess: return the latest loaded model's position or the fallback position.
InventoryModelPosition Inventory3DManager::GetLastModelPosition() const
{
    const InventoryModelPosition* position;
    if (!loadTask && loadedModelCount != 0) {
        const LoadedInventoryModel* data = models.local;
        if (modelCapacity >= 0) {
            data = models.heap;
        }
        position = &data[loadedModelCount - 1].spModel->position;
    } else {
        position = &inventoryDefaultPosition;
    }
    return *position;
}
