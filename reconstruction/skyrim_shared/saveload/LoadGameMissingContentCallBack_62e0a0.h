// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// LoadGameMissingContentCallBack, LoadGameMissingContentCallBack::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// MissingContentCallbackBase, MissingContentPayload, refCount, payload, unk18: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

class MissingContentPayload
{
public:
    virtual ~MissingContentPayload();
};

class MissingContentCallbackBase
{
public:
    virtual ~MissingContentCallbackBase() {}

    std::uint32_t refCount;  // 08
};
static_assert(sizeof(MissingContentCallbackBase) == 0x10, "MissingContentCallbackBase size");

class LoadGameMissingContentCallBack : public MissingContentCallbackBase
{
public:
    LoadGameMissingContentCallBack();
    ~LoadGameMissingContentCallBack() override;  // compared: 0x62e0a0

    MissingContentPayload* payload;  // 10
    std::uint64_t unk18;  // 18
};
static_assert(sizeof(LoadGameMissingContentCallBack) == 0x20, "LoadGameMissingContentCallBack size");
