// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function137350: GUESS(low)
// Array137350: GUESS(low)
#pragma once

#include <cstdint>

struct Array137350
{
    void ReleaseData();
    void* data;
    std::uint64_t unk08;
    std::uint32_t size;
};

void Function137350(Array137350* arr, bool release);
