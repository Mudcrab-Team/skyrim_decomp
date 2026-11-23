// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSExtraData, ExtraLock, ExtraLock::~ExtraLock: CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// ExtraLock::lock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class BSExtraData
{
public:
    virtual ~BSExtraData() {}
    std::uint8_t unk08[0x8];
};

struct REFR_LOCK;

class ExtraLock : public BSExtraData
{
public:
    ~ExtraLock() override;  // compared: 0x180eb0

    REFR_LOCK* lock;  // 0x10
    std::uint64_t unk18;
};
static_assert(sizeof(ExtraLock) == 32, "ExtraLock size");
