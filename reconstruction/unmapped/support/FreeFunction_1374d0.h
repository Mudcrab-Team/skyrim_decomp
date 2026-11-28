// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function1374d0: GUESS(low)
// ArraySizePart1374d0: GUESS(low)
// Array1374d0: GUESS(low)
#pragma once

#include <cstdint>

// guess: the CrashLogger PDB names the Shift call BSTArray::RemoveElements; the stand-in name is kept.
struct ArraySizePart1374d0
{
    void Shift(void* data, std::uint32_t dstIndex, std::uint32_t srcIndex, std::uint32_t count, std::uint32_t elemSize);
    std::uint32_t size;
};

struct Array1374d0
{
    void* data;
    std::uint64_t unk08;
    ArraySizePart1374d0 sizePart;
};

void Function1374d0(Array1374d0* arr, std::uint32_t dstIndex, std::uint32_t srcIndex, std::uint32_t count);
