// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// FileInterface_e15b00, BufferedFile_e15b00, Functione15b00, Slot0, Slot1, Slot2, Slot3, Slot4, Slot5, Slot6, Slot7, Slot8, Write, Slot10, Slot11, Slot12, Slot13, Slot14, Seek, unk00, file, buffer, mode, pos, limit, unk2C, fileOffset, data, count, offset, origin, bufferedFile: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct FileInterface_e15b00
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual std::int32_t Write(const void* data, std::int32_t count);
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual std::int64_t Seek(std::int64_t offset, std::int32_t origin);
};

struct BufferedFile_e15b00
{
    std::uint64_t unk00[2];       // 0x00
    FileInterface_e15b00* file;   // 0x10
    void* buffer;                 // 0x18
    std::uint32_t mode;           // 0x20
    std::int32_t pos;             // 0x24
    std::int32_t limit;           // 0x28
    std::uint32_t unk2C;          // 0x2C
    std::int64_t fileOffset;      // 0x30
};
static_assert(offsetof(BufferedFile_e15b00, file) == 0x10, "file offset");
static_assert(offsetof(BufferedFile_e15b00, mode) == 0x20, "mode offset");
static_assert(offsetof(BufferedFile_e15b00, fileOffset) == 0x30, "fileOffset offset");

void Functione15b00(BufferedFile_e15b00* bufferedFile);
