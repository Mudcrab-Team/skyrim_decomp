// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::vector over a stand-in 4-byte element
// SPDX-License-Identifier: CC0-1.0
// StdVecElem130240: GUESS(low) STANDIN
// std::vector<>::_Change_array: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <vector>

struct StdVecElem130240
{
    std::uint32_t value;
};
