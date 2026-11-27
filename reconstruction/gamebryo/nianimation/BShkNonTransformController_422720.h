// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, BShkNonTransformController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::DeleteThis, NiRefObject::refCount, NiRefObject::unk0C, NiRefPointer, NiRefPointer::object, BShkNonTransformController::unk08, BShkNonTransformController::target: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    long refCount;
    std::uint32_t unk0C;
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

struct NiRefPointer
{
    ~NiRefPointer()
    {
        NiRefObject* ptr = object;
        if (ptr) {
            // Decrement the shared intrusive reference count atomically and destroy on the final release.
            if (_InterlockedExchangeAdd(&ptr->refCount, -1) == 1) {
                ptr->DeleteThis();
            }
        }
    }

    NiRefObject* object;
};

class BShkNonTransformController
{
public:
    BShkNonTransformController();
    virtual ~BShkNonTransformController();

    std::uint64_t unk08;
    NiRefPointer target;
};
static_assert(offsetof(BShkNonTransformController, target) == 0x10, "target offset");
static_assert(sizeof(BShkNonTransformController) == 0x18, "BShkNonTransformController size");
