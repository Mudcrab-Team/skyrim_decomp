// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraDataList, BaseExtraList, BSExtraData, PresenceBitfield, bits, data, presence, next, GetType, _extraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetPreviousExtraDataToTypeUnsafe: CRASHLOGGER_PDB(59818@2026.10.24)
// table: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSExtraData
{
public:
    virtual ~BSExtraData();
    virtual std::uint32_t GetType() const;

    BSExtraData* next;  // 08
};
static_assert(offsetof(BSExtraData, next) == 0x08, "next offset");

class BaseExtraList
{
public:
    struct PresenceBitfield
    {
        std::uint8_t bits[0x17];
    };

    void*             table;     // 00
    BSExtraData*      data;      // 08
    PresenceBitfield* presence;  // 10
};
static_assert(offsetof(BaseExtraList, data) == 0x08, "data offset");
static_assert(offsetof(BaseExtraList, presence) == 0x10, "presence offset");

class ExtraDataList
{
public:
    BSExtraData* GetPreviousExtraDataToTypeUnsafe(std::uint32_t type) const;

    BaseExtraList _extraData;
};
