// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStringsExtraData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiFreeStorage, unk08, size, unk1C, strings: GUESS(low) STANDIN
#pragma once

#include <cstdint>

void NiFreeStorage(void* ptr);

class NiExtraData
{
public:
    virtual ~NiExtraData();

    std::uint64_t unk08[2];  // 08
};
static_assert(sizeof(NiExtraData) == 0x18, "NiExtraData size");

class NiStringsExtraData : public NiExtraData
{
public:
    NiStringsExtraData();
    ~NiStringsExtraData() override;

    std::uint32_t size;     // 18
    std::uint32_t unk1C;    // 1C
    char**        strings;  // 20
};
static_assert(sizeof(NiStringsExtraData) == 0x28, "NiStringsExtraData size");
