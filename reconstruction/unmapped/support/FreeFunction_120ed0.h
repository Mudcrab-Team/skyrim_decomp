// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// Stream120ed0, Function120ed0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct Stream120ed0
{
    std::uint64_t unk00;   // 0x00
    std::uint64_t unk08;   // 0x08
    std::uint64_t unk10;   // 0x10
    std::uint64_t unk18;   // 0x18
    std::int32_t size;     // 0x20
    std::int32_t position; // 0x24
};

std::int32_t Function120ed0(Stream120ed0* a_stream, std::int32_t a_bytes);  // compared: 0x120ed0
