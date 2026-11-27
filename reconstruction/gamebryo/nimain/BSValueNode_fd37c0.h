// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiPointer::~NiPointer as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiPointer, BSMasterParticleSystem, BSNiNode, BSValueNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::DeleteThis, BSValueNode::flags, BSValueNode::value, BSValueNode::associatedObject: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::refCount, NiRefObject::unk0C, NiRefObject::DecRefCount, NiPointer::_ptr, BSNiNode::unk08, BSValueNode::unk129: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    void DecRefCount()
    {
        // atomic reference count decrement required by intrusive smart pointers
        if (_InterlockedExchangeAdd(&refCount, -1) == 1) {
            DeleteThis();
        }
    }

    long refCount;
    std::uint32_t unk0C;
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

template <class T>
class NiPointer
{
public:
    ~NiPointer()
    {
        if (_ptr) {
            _ptr->DecRefCount();
        }
    }

    T* _ptr;
};

class BSMasterParticleSystem : public NiRefObject
{
};

class BSNiNode
{
public:
    virtual ~BSNiNode();

    std::uint8_t unk08[0x120];
};
static_assert(sizeof(BSNiNode) == 0x128, "BSNiNode size");

class BSValueNode : public BSNiNode
{
public:
    BSValueNode();
    ~BSValueNode() override = default;

    std::uint8_t flags;
    std::uint8_t unk129[3];
    std::uint32_t value;
    NiPointer<BSMasterParticleSystem> associatedObject;
};
static_assert(offsetof(BSValueNode, associatedObject) == 0x130, "associatedObject offset");
static_assert(sizeof(BSValueNode) == 0x138, "BSValueNode size");
