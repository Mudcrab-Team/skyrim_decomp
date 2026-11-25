// Source exposure: mixed
// Code origin: original partial declarations with source-derived names as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSaveGameBuffer, buffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSSaveLoadManager: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSSaveLoadFile: STANDIN SIBLING(fo4-private@1b765c70, author-permission)
// bSimulatedMode: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); name only, target-specific offset.
// Save, pSaveLoadManager: SIBLING(fo4-private@1b765c70, author-permission)
// write, position: GUESS(low); callback and accumulated write count.
// 0x639a20 BGSSaveGameBuffer::Save

#pragma once
#include <cstddef>
#include <cstdint>

class BGSSaveLoadManager
{
public:
    unsigned char unk000[0x120];
    bool bSimulatedMode;
};
extern BGSSaveLoadManager* pSaveLoadManager;

class BGSSaveLoadFile
{
public:
    void* unk00;
    std::uint32_t position;
    unsigned char unk0C[0x0C];
    std::uint32_t (*write)(BGSSaveLoadFile*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};
static_assert(offsetof(BGSSaveLoadFile, position) == 8, "written count offset");
static_assert(offsetof(BGSSaveLoadFile, write) == 0x18, "writer callback offset");

class BGSSaveGameBuffer
{
public:
    void Save(BGSSaveLoadFile* file, std::uint32_t size);
    void* unk00;
    void* buffer;
};
static_assert(offsetof(BGSSaveGameBuffer, buffer) == 8, "buffer offset");
