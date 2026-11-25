// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSDestructibleObjectForm, DestructibleObjectData, data, health, numStages, flags, stages, replacementModelRefCount, preloadedReplacementModels: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UnloadReplacementModels: SYMBOLS(fnv-x360-pdb)
// QueuedFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCount, unk00, unk06, unk14: GUESS(low); unexposed storage and observed reference count
#pragma once
#include <cstddef>
#include <cstdint>

class QueuedFile
{
public:
    virtual ~QueuedFile();
    // volatile: reference count is shared across threads.
    volatile long refCount; // 08
};

struct DestructibleObjectData
{
    std::uint32_t health; // 00
    std::int8_t numStages; // 04
    std::uint8_t flags; // 05
    std::uint16_t unk06; // 06
    void* stages; // 08
    // volatile: replacement model users synchronize across threads.
    volatile long replacementModelRefCount; // 10
    std::uint32_t unk14; // 14
    QueuedFile* preloadedReplacementModels; // 18
};

class BGSDestructibleObjectForm
{
public:
    void UnloadReplacementModels();
    std::uint64_t unk00; // 00
    DestructibleObjectData* data; // 08
};
static_assert(offsetof(BGSDestructibleObjectForm, data) == 0x08, "data offset");
static_assert(offsetof(DestructibleObjectData, replacementModelRefCount) == 0x10, "count offset");
static_assert(offsetof(DestructibleObjectData, preloadedReplacementModels) == 0x18, "models offset");
