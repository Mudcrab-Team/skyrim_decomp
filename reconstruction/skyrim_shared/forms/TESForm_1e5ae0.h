// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm: EXE_RTTI
// TESForm::GetFile, TESForm::sourceFiles, TESFileContainer, TESFileContainer::array, TESFileArray, TESFileArray::data, TESFileArray::size, TESFile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm::unk00: GUESS(low); untouched base storage before sourceFiles
#pragma once

#include <cstddef>
#include <cstdint>

class TESFile;

struct TESFileArray
{
    TESFile* operator[](std::uint32_t a_index) const { return data[a_index]; }

    TESFile**    data;  // 00
    std::int32_t size;  // 08
};
static_assert(offsetof(TESFileArray, size) == 0x8, "TESFileArray::size offset");

struct TESFileContainer
{
    TESFileArray* array;  // 00
};

class TESForm
{
public:
    TESFile* GetFile(std::int32_t a_idx) const;

    std::uint8_t     unk00[0x8];   // 00
    TESFileContainer sourceFiles;  // 08
};
static_assert(offsetof(TESForm, sourceFiles) == 0x8, "TESForm::sourceFiles offset");
