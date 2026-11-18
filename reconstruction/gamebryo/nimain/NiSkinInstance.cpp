// Code origin: Reconstruction by v-macrev with Codex assistance from pinned-image analysis, informed by the cited sibling serialization and comparison shapes.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/niskininstance.cpp:8
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/niskininstance.cpp:32
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/niskininstance.cpp:58
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/niskininstance.cpp:187
// Adapted bodies: SaveBinary, RegisterStreamables and IsEqual use the cited sibling control flow, with layout, call sites and argument order checked against the pinned image; LoadBinary was reconstructed from the pinned image.
// 0xef6f50 NiSkinInstance::~NiSkinInstance
// 0xf096a0 NiSkinInstance::LoadBinary
// 0xf09820 NiSkinInstance::RegisterStreamables
// 0xf098d0 NiSkinInstance::SaveBinary
// 0xf09990 NiSkinInstance::IsEqual
// 0xf09ca0 NiSkinInstance::Unk_25
// 0xf0a690 NiSkinInstance::Ctor
#include "NiSkinInstance.h"

#include <cstddef>
#include <new>

// InitializeCriticalSection: OBSERVED; named Windows import for the instance lock
// lockStorage, UpdatePartition, partition: GUESS(low)
extern "C" __declspec(dllimport) void InitializeCriticalSection(SkinInstanceLock* lockStorage) noexcept;
void UpdatePartition(NiObject* partition);

SkinInstanceLock::SkinInstanceLock() noexcept
{
    InitializeCriticalSection(this);
}

// The complete destructor is external. Its declaration lets the compiler emit the deleting
// destructor beside the constructor's virtual table.
NiSkinInstance::NiSkinInstance() :
    rootParent(nullptr),
    bones(nullptr),
    boneWorldTransforms(nullptr),
    numMatrices(0),
    numRegisters(0),
    allocatedSize(0),
    boneMatrices(nullptr),
    prevBoneMatrices(nullptr),
    skinToWorldWorldToSkinMatrix(nullptr)
{
}

NiSkinInstance* NiSkinInstance::Ctor()
{
    return new (this) NiSkinInstance;
}

void NiSkinInstance::LoadBinary(NiStream& streamRef)
{
    NiObject::LoadBinary(streamRef);
    streamRef.LoadLinkID();
    streamRef.LoadLinkID();
    streamRef.LoadLinkID();
    streamRef.SkipLinkIDs();
}

// boneCount, index, other: GUESS(low)
bool NiSkinInstance::RegisterStreamables(NiStream& streamRef)
{
    if (!NiObject::RegisterStreamables(streamRef)) {
        return false;
    }
    skinData.get()->RegisterStreamables(streamRef);
    if (skinPartition.get()) {
        skinPartition.get()->RegisterStreamables(streamRef);
    }
    rootParent->RegisterStreamables(streamRef);

    const std::uint32_t boneCount = skinData.get()->bones;
    for (std::uint32_t index = 0; index < boneCount; ++index) {
        bones[index]->RegisterStreamables(streamRef);
    }
    return true;
}

void NiSkinInstance::SaveBinary(NiStream& streamRef)
{
    NiObject::SaveBinary(streamRef);
    streamRef.SaveLinkID(skinData.get());
    streamRef.SaveLinkID(skinPartition.get());
    streamRef.SaveLinkID(rootParent);
    std::uint32_t boneCount = skinData.get()->bones;
    streamRef.oStr->write(&boneCount, 1);
    for (std::uint32_t index = 0; index < boneCount; ++index) {
        streamRef.SaveLinkID(bones[index]);
    }
}

bool NiSkinInstance::IsEqual(NiObject* comparedObject)
{
    if (!NiObject::IsEqual(comparedObject)) {
        return false;
    }
    auto* other = static_cast<NiSkinInstance*>(comparedObject);
    if (!skinData.get()->IsEqual(other->skinData.get())) {
        return false;
    }
    if (skinPartition.get() && !skinPartition.get()->IsEqual(other->skinPartition.get())) {
        return false;
    }
    if (!skinPartition.get() && other->skinPartition.get()) {
        return false;
    }
    return true;
}

void NiSkinInstance::Unk_25()
{
    UpdatePartition(skinPartition.get());
}
