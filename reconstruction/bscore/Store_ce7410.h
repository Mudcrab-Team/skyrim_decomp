// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CompactingStore: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IMemoryStoreBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Store, unk08, allocBase, unk18, tlsIndex, unk29C: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, std::size_t size, std::uint32_t freeType);
extern "C" __declspec(dllimport) int __stdcall TlsFree(std::uint32_t tlsIndex);

class IMemoryStoreBase
{
public:
    IMemoryStoreBase();
    virtual ~IMemoryStoreBase();
};
static_assert(sizeof(IMemoryStoreBase) == 0x8, "IMemoryStoreBase size");

namespace CompactingStore
{
    class Store : public IMemoryStoreBase
    {
    public:
        Store();
        ~Store() override
        {
            VirtualFree(allocBase, 0, 0x8000);
            TlsFree(tlsIndex);
        }

        std::uint8_t  unk08[0x8];    // 008
        void*         allocBase;     // 010
        std::uint8_t  unk18[0x280];  // 018
        std::uint32_t tlsIndex;      // 298
        std::uint32_t unk29C;        // 29C
    };
    static_assert(sizeof(Store) == 0x2A0, "CompactingStore::Store size");
}
