// Source exposure: mixed (local target analysis and permitted name/layout references).
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorProcess: EXE_RTTI
// UnlockForDemandedAnimationSet: SYMBOLS(tesv-2013-map); candidate name from AIProcess
// MiddleHighProcessData, BSSpinLock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// middleHigh, unk1E8, _owningThread, _lockCount, Unlock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetCurrentThreadId: OBSERVED
// padding: GUESS(low); unused layout ranges
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
class BSSpinLock
{
public:
    std::uint32_t _owningThread;
    std::uint32_t _lockCount;

    void Unlock()
    {
        // Acquire prior protected reads before checking ownership.
        _mm_lfence();
        if (_owningThread != GetCurrentThreadId()) {
            return;
        }
        if (_lockCount == 1) {
            _owningThread = 0;
            // Publish owner clearance before releasing the final hold.
            _mm_mfence();
            // Release only a single outstanding recursive hold.
            _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&_lockCount), 0, 1);
        } else {
            // Nested holds release one recursion level atomically.
            _InterlockedDecrement(reinterpret_cast<volatile long*>(&_lockCount));
        }
    }
};
struct MiddleHighProcessData
{
    std::uint8_t padding[0x1E8];
    BSSpinLock unk1E8;
};
class ActorProcess
{
public:
    void UnlockForDemandedAnimationSet();
    std::uint8_t padding[8];
    MiddleHighProcessData* middleHigh;
};
static_assert(offsetof(MiddleHighProcessData, unk1E8) == 0x1E8, "lock offset");
static_assert(offsetof(ActorProcess, middleHigh) == 8, "middle high offset");
