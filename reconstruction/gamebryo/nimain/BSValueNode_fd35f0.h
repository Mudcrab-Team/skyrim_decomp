// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSValueNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSValueNode::ParseIndexFromName, BSValueNode::value: CRASHLOGGER_PDB(59818@2026.10.24)
// BSValueNode::unk00, BSValueNode::name, BSValueNode::unk18: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSValueNode
{
public:
    bool ParseIndexFromName();

    std::uint8_t unk00[0x10];
    const char* name;
    std::uint8_t unk18[0x114];
    std::int32_t value;
};
static_assert(offsetof(BSValueNode, name) == 0x10, "name offset");
static_assert(offsetof(BSValueNode, value) == 0x12C, "value offset");
