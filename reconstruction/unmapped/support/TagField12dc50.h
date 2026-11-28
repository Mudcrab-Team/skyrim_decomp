// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// Base12dc50, TagField12dc50: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

struct Base12dc50
{
    virtual ~Base12dc50();

    std::uint64_t unk08[10];  // 0x08
};

static_assert(sizeof(Base12dc50) == 0x58, "Base12dc50 size");

struct TagField12dc50 : Base12dc50
{
    TagField12dc50();
    ~TagField12dc50() override;  // compared: 0x12dc50

    std::vector<void*> items;  // 0x58
    std::uint64_t unk70;       // 0x70
};

static_assert(sizeof(TagField12dc50) == 0x78, "TagField12dc50 size");
