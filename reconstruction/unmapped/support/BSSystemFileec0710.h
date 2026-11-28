// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// BSSystemFileec0710, DoGetSize, GetFileSizeEx, unk00, handle, fileHandle, outSize: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __stdcall GetFileSizeEx(void* fileHandle, std::uint64_t* outSize);

class BSSystemFileec0710
{
public:
    std::uint64_t unk00;  // 0x00
    void* handle;         // 0x08

    std::uint32_t DoGetSize(std::uint64_t* outSize);
};
static_assert(offsetof(BSSystemFileec0710, handle) == 0x08, "handle offset");
