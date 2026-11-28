// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function137300: GUESS(low)
// ArraySizePart137300: GUESS(low)
// Array137300: GUESS(low)
#pragma once

#include <cstdint>

// guess: the CrashLogger PDB names the Shift call BSTArray::RemoveElements; the stand-in name is kept.
struct ArraySizePart137300
{
    void Shift(void* data, std::uint32_t dstIndex, std::uint32_t srcIndex, std::uint32_t count, std::uint32_t elemSize);
    std::uint32_t size;
};

struct Array137300
{
    void* data;
    std::uint64_t unk08;
    ArraySizePart137300 sizePart;
};

void Function137300(Array137300* arr, std::uint32_t index);
