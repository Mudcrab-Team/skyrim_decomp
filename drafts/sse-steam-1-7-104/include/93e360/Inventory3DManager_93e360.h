// Exposure detail: (local target analysis and community declarations).
// Source exposure: mixed
// Code origin: original reconstruction from target observations and attributed community material.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Inventory3DManager, LoadedInventoryModel, itemBase, modelObj, spModel, loadTask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations and name hints.
// GetLastModelPosition, InventoryModelPosition, InventoryLoadedObject, position, modelCapacity, models, loadedModelCount, inventoryDefaultPosition, unknown ranges: GUESS(low); target-accessed fields inferred locally.
// 0x93e360 Inventory3DManager::GetLastModelPosition

#pragma once
#include <cstdint>
struct InventoryModelPosition
{
    InventoryModelPosition(const InventoryModelPosition& other) : x(other.x), y(other.y), z(other.z) {}
    std::uint32_t x;
    std::uint32_t y;
    std::uint32_t z;
};
struct InventoryLoadedObject
{
    std::uint8_t unknown00[0xA0];
    InventoryModelPosition position;  // A0
};
struct LoadedInventoryModel
{
    void* itemBase;
    void* modelObj;
    InventoryLoadedObject* spModel;  // 10
    std::uint64_t unknown18;
};
extern const InventoryModelPosition inventoryDefaultPosition;
class Inventory3DManager
{
public:
    InventoryModelPosition GetLastModelPosition() const;
    std::uint8_t unknown00[0x60];
    std::int32_t modelCapacity;  // 60, high bit marks inline storage
    std::uint32_t unknown64;
    union ModelStorage
    {
        LoadedInventoryModel* heap;
        LoadedInventoryModel local[7];
    } models;  // 68
    std::uint32_t loadedModelCount;  // 148
    std::uint8_t unknown14c[0xC];
    void* loadTask;  // 158
};
