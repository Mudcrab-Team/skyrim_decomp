// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction with the declared community destructor adaptation.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ScrapHeap, IMemoryStore, baseAddress: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// VirtualFree: OBSERVED; Windows API declaration.
// unknown08: OBSERVED; unmodelled heap bookkeeping before baseAddress.
#pragma once
#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, std::size_t size, unsigned long type);
class IMemoryStore
{
public:
    virtual ~IMemoryStore();
};
class ScrapHeap : public IMemoryStore
{
public:
    ~ScrapHeap() override;
    std::uint64_t unknown08[8];
    void* baseAddress;
};
