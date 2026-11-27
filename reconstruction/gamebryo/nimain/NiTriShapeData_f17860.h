// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiTriShapeData, NiTriShapeData::Functionf17860: GUESS(low)
// NiTriShapeData::unk78: OBSERVED
// NiTriShapeData::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiTriShapeData
{
public:
    std::uint64_t Functionf17860();
    std::uint8_t unknown00[120];
    std::uint64_t unk78;
};

static_assert(offsetof(NiTriShapeData, unk78) == 120, "field offset");
