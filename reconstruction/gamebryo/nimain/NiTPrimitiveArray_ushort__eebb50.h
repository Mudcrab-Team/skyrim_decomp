// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiTPrimitiveArray_ushort_, NiTPrimitiveArray_ushort_::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// NiFree, data, size, capacity, growSize: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;
void NiFree(void* a_ptr);

class NiTPrimitiveArray_ushort_
{
public:
    NiTPrimitiveArray_ushort_();
    virtual ~NiTPrimitiveArray_ushort_();

    std::uint16_t* data;      // 08
    std::uint16_t  capacity;  // 10
    std::uint16_t  firstFree; // 12
    std::uint16_t  size;      // 14
    std::uint16_t  growSize;  // 16
};
static_assert(sizeof(NiTPrimitiveArray_ushort_) == 0x18, "NiTPrimitiveArray_ushort_ size");
