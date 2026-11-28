// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// TagField: GUESS(low) STANDIN
// TagField::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// Base12dcd0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

struct Base12dcd0
{
    virtual ~Base12dcd0();

    std::uint64_t unk08[10];  // 0x08
};

static_assert(sizeof(Base12dcd0) == 0x58, "Base12dcd0 size");

class TagField : public Base12dcd0
{
public:
    TagField();
    ~TagField() override;  // compared deleting destructor: 0x12dcd0

    std::vector<void*> items;  // 0x58
    std::uint64_t unk70;       // 0x70
};

static_assert(sizeof(TagField) == 0x78, "TagField size");
