// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ExtraBiped, BSExtraData, BipedAnim, biped: CRASHLOGGER_PDB(59818@2026.10.24)
// BipedAnimPtr, next, refCount: GUESS(low)
#pragma once

#include <intrin.h>

class BipedAnim
{
public:
    long refCount;  // 00
};

struct BipedAnimPtr
{
    BipedAnimPtr(const BipedAnimPtr& a_rhs) : ptr(a_rhs.ptr)
    {
        if (a_rhs.ptr) {
            // atomic reference increment for shared biped animation pointer
            _InterlockedIncrement(&a_rhs.ptr->refCount);
        }
    }

    BipedAnim* ptr;
};

class BSExtraData
{
public:
    BSExtraData() { next = nullptr; }
    virtual ~BSExtraData();

    BSExtraData* next;  // 08
};

class ExtraBiped : public BSExtraData
{
public:
    explicit ExtraBiped(const BipedAnimPtr& a_biped);  // compared: 0x180980

    BipedAnimPtr biped;  // 10
};
static_assert(sizeof(ExtraBiped) == 0x18, "ExtraBiped size");
