// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial TESFile and BSFile layouts follow the cited declarations.
// TESFile, BSFile, BSFile::seek, FORM, FORM::form, FORM::length: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFile::file, fileName, currentform: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFile::saveform, saveFormOffset, saveChunkOffset, isBigEndian, unk430, recordFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFile::ReadFormHeader, ReadChunkHeader, SeekRaw, Function declarations, FunctionSlot declarations, padding: GUESS(low)
// IsRecordFileLoaded: GUESS(low); name follows the existing TESWorldSpace unit.
// SubrecordHeader, SubrecordValue: STANDIN GUESS(low)
// SubrecordHeader::id, ::size: OBSERVED; grouped fields at TESFile::currentchunkID and TESFile::actualChunkSize in the cited layout.
#pragma once

#include <cstdint>

class BSFile
{
public:
    virtual ~BSFile();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual void FunctionSlot04();
    virtual void FunctionSlot05();
    virtual void seek(std::int32_t offset, std::int32_t origin);
};

struct FORM
{
    std::uint32_t form;
    std::uint32_t length;
    std::uint8_t padding08[0x10];
};
static_assert(sizeof(FORM) == 0x18, "form header size");

struct SubrecordHeader
{
    std::uint32_t id;
    std::uint32_t size;
};

struct SubrecordValue
{
    std::uint8_t padding00[8];
    std::uint32_t value;
};
static_assert(sizeof(SubrecordValue) == 0xC, "subrecord data size");

class TESFile
{
public:
    bool Function1cd5d0();
    void Function1cd780(bool skipChunk);
    std::uint32_t Function1cdb10(std::uint32_t offset);
    bool Function1cdf40(const char* name);
    bool Function1ce2d0();
    bool IsRecordFileLoaded();
    bool Function1ce420() const;
    bool Function1ce4c0() const;
    void Function1ce4e0(bool checked);
    bool Function1ce510() const;
    void Function1ce580(bool active);
    bool Function1ce5b0() const;
    bool Function1ce650() const;
    bool Function27d2e0(SubrecordValue& data);

private:
    bool ReadFormHeader();
    bool ReadChunkHeader();
    void SeekRaw(std::uint32_t offset, std::uint32_t origin);
    bool Function1cdd10(void* data, std::uint32_t size);
    bool Function1cfe50(const void* data, std::uint32_t size);

    std::uint8_t padding000[0x38];
    BSFile* file;
    std::uint8_t padding040[0x18];
    char fileName[260];
    std::uint8_t padding15C[0x284 - 0x15C];
    FORM currentform;
    SubrecordHeader chunk;
    std::uint8_t padding2A4[0x10];
    FORM saveform;
    std::uint32_t saveFormOffset;
    std::uint64_t saveChunkOffset;
    std::uint8_t padding2D8[0x11];
    bool isBigEndian;
    std::uint8_t padding2EA[0x430 - 0x2EA];
    std::uint32_t unk430;
    std::uint8_t padding434[4];
    std::uint32_t recordFlags;
};
