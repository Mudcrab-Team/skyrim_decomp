// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0x1cd5d0 TESFile::Function1cd5d0
// 0x1cd780 TESFile::Function1cd780
// 0x1cdb10 TESFile::Function1cdb10
// 0x1cdf40 TESFile::Function1cdf40
// 0x1ce2d0 TESFile::Function1ce2d0
// 0x1ce3e0 TESFile::IsRecordFileLoaded
// 0x1ce420 TESFile::Function1ce420
// 0x1ce4c0 TESFile::Function1ce4c0
// 0x1ce4e0 TESFile::Function1ce4e0
// 0x1ce510 TESFile::Function1ce510
// 0x1ce580 TESFile::Function1ce580
// 0x1ce5b0 TESFile::Function1ce5b0
// 0x1ce650 TESFile::Function1ce650
// 0x27d2e0 TESFile::Function27d2e0
#include "TESFile_1cd5d0.h"

#include <cstring>
#include <intrin.h>

// FormType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// seekOrigin, ConvertFormType: GUESS(low)
enum class FormType : std::uint32_t;
extern const std::uint32_t seekOrigin;
FormType ConvertFormType(std::uint32_t recordType);

bool TESFile::Function1cd5d0()
{
    if (currentform.form != 0) {
        chunk.id = 0;
        chunk.size = 0;
        return ReadChunkHeader();
    }
    return false;
}

void TESFile::Function1cd780(bool skipChunk)
{
    if (currentform.form == 0 && ReadFormHeader()) {
        chunk.id = 0;
        chunk.size = 0;
        if (!skipChunk) {
            ReadChunkHeader();
        }
    }
}

std::uint32_t TESFile::Function1cdb10(std::uint32_t offset)
{
    SeekRaw(offset, seekOrigin);
    if (!ReadFormHeader()) {
        return 0;
    }
    return static_cast<std::uint32_t>(ConvertFormType(currentform.form));
}

bool TESFile::Function1cdf40(const char* name)
{
    if (!name || std::strlen(name) >= sizeof(fileName)) {
        return false;
    }
    strcpy_s(fileName, sizeof(fileName), name);
    return true;
}

bool TESFile::Function1ce2d0()
{
    ++unk430;
    saveform.length = static_cast<std::uint32_t>(saveChunkOffset);
    file->seek(saveFormOffset, seekOrigin);
    return Function1cfe50(&saveform, sizeof(saveform));
}

bool TESFile::IsRecordFileLoaded()
{
    return static_cast<std::uint8_t>(recordFlags) & 1u;
}

bool TESFile::Function1ce420() const
{
    return (recordFlags >> 9) & 1u;
}

bool TESFile::Function1ce4c0() const
{
    return (static_cast<std::uint8_t>(recordFlags) >> 4) & 1u;
}

void TESFile::Function1ce4e0(bool checked)
{
    const auto flags = recordFlags;
    if (!checked) {
        recordFlags = flags & ~0xCu;
    } else {
        recordFlags = flags | 4u;
    }
}

bool TESFile::Function1ce510() const
{
    return (static_cast<std::uint8_t>(recordFlags) >> 2) & 1u;
}

void TESFile::Function1ce580(bool active)
{
    const auto flags = recordFlags;
    recordFlags = active ? flags | 8u : flags & ~8u;
}

bool TESFile::Function1ce5b0() const
{
    return (static_cast<std::uint8_t>(recordFlags) >> 3) & 1u;
}

bool TESFile::Function1ce650() const
{
    return (recordFlags >> 7) & 1u;
}

bool TESFile::Function27d2e0(SubrecordValue& data)
{
    if (isBigEndian && chunk.size < sizeof(data)) {
        // Convert the retained field before reading a short big-endian subrecord.
        data.value = _byteswap_ulong(data.value);
    }
    const auto read = Function1cdd10(&data, sizeof(data));
    if (isBigEndian) {
        // Convert the big-endian field back to host byte order.
        data.value = _byteswap_ulong(data.value);
    }
    return read;
}
