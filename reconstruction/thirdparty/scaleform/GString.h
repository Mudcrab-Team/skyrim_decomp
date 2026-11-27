// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GString, GString::GString, GString::DataDesc, GString::DataDesc::AddRef, GString::BernsteinHashFunction, GString::BernsteinHashFunctionCIS: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GString::BernsteinHashFunctionCIS: CRASHLOGGER_PDB(59818@2026.10.24)
// GString::NullData: GUESS(low); the shared empty string descriptor a default string points at.
// GString::pData: GUESS(low)
#pragma once

#include <intrin.h>
#include <cstdint>
#include <cstddef>

class GString
{
public:
    struct DataDesc
    {
        void AddRef()
        {
            // Strings share descriptors across threads, so the count changes atomically.
            _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&refCount), 1);
        }

        std::size_t capacity;  // 00
        // volatile: descriptors are shared across threads and counted atomically.
        volatile std::int32_t refCount;  // 08
        char data[1];  // 0C
    };
    static_assert(sizeof(DataDesc) == 0x10, "GString::DataDesc size");

    GString();

    static std::size_t BernsteinHashFunction(const void* dataIn, std::size_t size, std::size_t seed = 5381);
    static std::size_t BernsteinHashFunctionCIS(const void* dataIn, std::size_t size, std::size_t seed = 5381);

    static DataDesc NullData;

    DataDesc* pData;  // 00
};
static_assert(sizeof(GString) == 0x8, "GString size");
