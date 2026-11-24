// Source exposure: mixed (pinned image, community and sibling declarations).
// Code origin: Class view from the pinned image and labelled declarations. The destructor follows the cited FNV method.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFile, BSFile::~BSFile, FlushBuffer: CRASHLOGGER_PDB(59818@2026.10.24)
// NiFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// file, isGood: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Close: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// ReleaseBuffer, unk08, unk40: GUESS(low)
// Adapted bodies: BSFile::~BSFile follows momusdigital/fnv_decomp@91e1b6e8 src/bssystem/bsfile.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bssystem/bsfile.cpp:55
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:26763
#pragma once

#include <cstdint>

class NiFile
{
public:
    virtual ~NiFile();
    bool FlushBuffer();

protected:
    std::uint64_t unk08[6];
    void* file;
    std::uint32_t unk40;
    bool isGood;
};
static_assert(sizeof(NiFile) == 0x48, "NiFile size");

class BSFile : public NiFile
{
public:
    ~BSFile() override;

private:
    void Close();
    void ReleaseBuffer();
};
