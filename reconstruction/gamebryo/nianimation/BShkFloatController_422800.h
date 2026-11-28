// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: reconstruction from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiRefPtr::~NiRefPtr, treated as adapted: it has the shape of NiPointer::~NiPointer, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: CC0-1.0
// BShkFloatController: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefTarget, NiRefPtr, DeleteThis, refCount, unknown08, target: GUESS(low)
#pragma once

#include <intrin.h>
#include <cstdint>

class NiRefTarget
{
public:
    virtual ~NiRefTarget();
    virtual void DeleteThis();  // slot 01 (+0x08)

    long refCount;     // 08
    std::uint32_t reserved0C;
};

struct NiRefPtr
{
    ~NiRefPtr()
    {
        NiRefTarget* obj = ptr;
        if (obj) {
            // atomic reference decrement before virtual deletion
            if (_InterlockedExchangeAdd(&obj->refCount, -1) == 1) {
                obj->DeleteThis();
            }
        }
    }

    NiRefTarget* ptr;
};

class BShkFloatController
{
public:
    BShkFloatController();
    virtual ~BShkFloatController();  // deleting dtor compared: 0x422800

    std::uint64_t unknown08;  // 08
    NiRefPtr target;          // 10
};
static_assert(sizeof(BShkFloatController) == 0x18, "BShkFloatController size");
