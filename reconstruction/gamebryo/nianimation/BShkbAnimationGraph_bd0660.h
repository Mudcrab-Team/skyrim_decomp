// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BShkbAnimationGraph: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// HashedAnimEntry, HashedAnimEntry::unk00, AnimGraphData, AnimGraphData::unk00, AnimGraphData::entries, AnimGraphData::unk48, AnimGraphData::count, GetDefaultHashedAnim, BShkbAnimationGraph::Functionbd0660, BShkbAnimationGraph::unk00, BShkbAnimationGraph::data: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct HashedAnimEntry
{
    std::uint8_t unk00[0x20];
};
static_assert(sizeof(HashedAnimEntry) == 0x20, "HashedAnimEntry size");

struct AnimGraphData
{
    std::uint8_t unk00[0x40];
    HashedAnimEntry* entries;
    std::uint64_t unk48;
    std::uint32_t count;
};
static_assert(offsetof(AnimGraphData, entries) == 0x40, "entries offset");
static_assert(offsetof(AnimGraphData, count) == 0x50, "count offset");

const HashedAnimEntry* GetDefaultHashedAnim();

class BShkbAnimationGraph
{
public:
    const HashedAnimEntry* Functionbd0660(std::int16_t a_index) const;

    std::uint8_t unk00[0x200];
    AnimGraphData* data;
};
static_assert(offsetof(BShkbAnimationGraph, data) == 0x200, "data offset");
