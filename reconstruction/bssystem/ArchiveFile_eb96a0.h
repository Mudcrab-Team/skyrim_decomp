// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original; declarations reduced from pinned community headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ArchiveFile: EXE_RTTI
// NiFile, NiFile::bufferAllocSize, NiFile::bufferReadSize, NiFile::pos, NiFile::buffer, NiFile::isGood, NiFile::pad2C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InitializeBuffer, AllocateBuffer, reserved, fileAndMode: GUESS(low); inferred initialization and storage roles.
// 0xeb96a0 ArchiveFile::InitializeBuffer
#pragma once
#include <cstddef>
#include <cstdint>

// NiFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiFile
{
public:
    std::uint8_t reserved[0x20];
    std::uint32_t bufferAllocSize;
    std::uint32_t bufferReadSize;
    std::uint32_t pos;
    std::uint32_t pad2C;
    char* buffer;
    std::uint8_t fileAndMode[0xC];
    bool isGood;
};
class ArchiveFile : public NiFile
{
public:
    bool InitializeBuffer();
};
static_assert(offsetof(ArchiveFile, bufferAllocSize) == 0x20, "buffer size offset");
static_assert(offsetof(ArchiveFile, buffer) == 0x30, "buffer offset");
static_assert(offsetof(ArchiveFile, isGood) == 0x44, "status offset");
char* AllocateBuffer(std::size_t a_size);
