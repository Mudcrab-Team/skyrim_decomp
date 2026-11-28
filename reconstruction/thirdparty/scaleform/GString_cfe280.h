// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GString, DataDesc, AddRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Clear: CRASHLOGGER_PDB(59818@2026.10.24)
// GMemoryHeap, GMemory, pGlobalHeap, Free, NullData, pData, bits, Release, Unk_01..Unk_0B: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class GMemoryHeap
{
public:
    virtual ~GMemoryHeap();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09(); virtual void Unk_0A(); virtual void Unk_0B();
    virtual void Free(void* ptr);  // 60
};

class GMemory
{
public:
    static GMemoryHeap* pGlobalHeap;
};

class GString
{
public:
    struct DataDesc
    {
        void AddRef()
        {
            // hot path: atomic string descriptor reference count increment
            _InterlockedExchangeAdd(&refCount, 1);
        }

        void Release()
        {
            // hot path: atomic string descriptor reference count release
            if (_InterlockedExchangeAdd(&refCount, -1) == 1)
            {
                GMemory::pGlobalHeap->Free(this);
            }
        }

        std::size_t   capacity;  // 00
        // volatile: descriptors are shared across threads and counted atomically
        volatile long refCount;  // 08
        char                    data[1];   // 0C
    };
    static_assert(sizeof(DataDesc) == 0x10, "GString::DataDesc size");

    void Clear();

    static DataDesc NullData;

    union
    {
        DataDesc*      pData;
        std::uintptr_t bits;
    };
};
static_assert(sizeof(GString) == 0x8, "GString size");
