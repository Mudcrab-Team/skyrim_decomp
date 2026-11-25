// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: original reconstruction; community names and declarations as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLoadGameBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
#include <cstddef>

// BGSLoadGameBuffer, buffer, bufferPosition: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSLoadGameBuffer: CRASHLOGGER_PDB(59818@2026.10.24); receiver offsets corroborate the community layout.
class BGSLoadGameBuffer
{
public:
    void* vtable;
    const std::uint8_t* buffer;
    std::uint8_t unknown10[0x14];
    std::uint32_t bufferPosition;
    // 0x637eb0 BGSLoadGameBuffer::ReadBlock16
    // ReadBlock16: GUESS(low); copies sixteen bytes and forwards a local block.
    void ReadBlock16(void* output);
};
static_assert(offsetof(BGSLoadGameBuffer, buffer) == 0x8, "buffer offset");
static_assert(offsetof(BGSLoadGameBuffer, bufferPosition) == 0x24, "position offset");
