// Exposure detail: (community declarations and local binary analysis).
// Source exposure: mixed
// Code origin: original hand-written reconstruction; community declarations and permitted sibling method names.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Inventory3DManager, LoadedInventoryModel, NiAVObject, NiMatrix3, NiTransform, NiPoint3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// loadedModels, spModel, entry, local, world, rotate, translate, scale, x, y, z, loadTask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// modelCapacity, loadedModelCount, modelStorage, unused: GUESS(low); partial array layout observed locally
// Inventory3DManager::GetModelRotation: SIBLING(fo4-private@1b765c70, author-permission)
// NiAVObject, LoadedInventoryModel: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)

#pragma once
#include <cstddef>
#include <cstdint>

struct NiMatrix3 { float entry[3][3]; };
struct NiPoint3 { float x, y, z; };
struct NiTransform
{
    NiMatrix3 rotate;
    NiPoint3 translate;
    float scale;
};
struct NiAVObject
{
    std::uint8_t unused[0x48];
    NiTransform local;
    NiTransform world;
};
struct LoadedInventoryModel
{
    void* itemBase;
    void* modelObj;
    NiAVObject* spModel;
    std::uint64_t unk18;
};
// itemBase, modelObj, unk18: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class Inventory3DManager
{
public:
    // 0x93e3d0 Inventory3DManager::GetModelRotation
    NiMatrix3 GetModelRotation() const;
    std::uint8_t unused[0x60];
    std::uint32_t modelCapacity;
    std::uint32_t unused64;
    union ModelStorage
    {
        LoadedInventoryModel* externalModels;
        LoadedInventoryModel inlineModels[7];
    } modelStorage;
    std::uint32_t loadedModelCount;
    std::uint8_t unused14c[0xC];
    void* loadTask;
};
// ModelStorage, externalModels, inlineModels, unused64, unused14c: GUESS(low); partial small-array storage
static_assert(offsetof(Inventory3DManager, modelStorage) == 0x68, "model storage offset");
static_assert(offsetof(Inventory3DManager, loadedModelCount) == 0x148, "model count offset");
static_assert(offsetof(Inventory3DManager, loadTask) == 0x158, "load task offset");
static_assert(offsetof(NiAVObject, world) == 0x7C, "rotation offset");
