// Source exposure: mixed (local target analysis and permitted name/layout references).
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorProcess: EXE_RTTI
// GetRagdollPenetrationUtil: SYMBOLS(fo4-pdb); candidate name from AIProcess
// MiddleHighProcessData, bhkRagdollPenetrationUtil: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// middleHigh, penetrationDetectUtil: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PenetrationPointer, Assign, pointer, refCount, padding: STANDIN GUESS(low); minimal intrusive ownership layout
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>

class bhkRagdollPenetrationUtil
{
public:
    virtual ~bhkRagdollPenetrationUtil();
    volatile long refCount;
};
struct PenetrationPointer
{
    bhkRagdollPenetrationUtil* pointer = nullptr;

    void Assign(const PenetrationPointer& other)
    {
        bhkRagdollPenetrationUtil* incoming = other.pointer;
        bhkRagdollPenetrationUtil* previous = pointer;
        if (incoming != previous) {
            if (incoming) {
                // Retain shared ownership before publishing the pointer.
                _InterlockedIncrement(&incoming->refCount);
            }
            pointer = incoming;
            if (previous) {
                // The previous owner is deleted only on the final atomic release.
                if (_InterlockedExchangeAdd(&previous->refCount, -1) == 1) {
                    delete previous;
                }
            }
        }
    }
};
struct MiddleHighProcessData
{
    std::uint8_t padding[0x258];
    PenetrationPointer penetrationDetectUtil;
};
class ActorProcess
{
public:
    bool GetRagdollPenetrationUtil(PenetrationPointer& output) const;
    std::uint8_t padding[8];
    MiddleHighProcessData* middleHigh;
};
static_assert(offsetof(MiddleHighProcessData, penetrationDetectUtil) == 0x258, "utility offset");
static_assert(offsetof(ActorProcess, middleHigh) == 8, "middle high offset");
