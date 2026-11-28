// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj24afc0::SetSize, treated as adapted: shaped like NiTArray::SetSize in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitarray.inl:97
// SPDX-License-Identifier: CC0-1.0
// 0x24afc0 Obj24afc0::SetSize
#include "Obj24afc0.h"

// Resize the backing pointer array, preserving existing entries and clearing truncated slots.
void Obj24afc0::SetSize(std::uint32_t newSize)
{
    if (newSize == maxSize)
    {
        return;
    }

    if (newSize < firstFree)
    {
        for (std::uint32_t i = newSize; i < firstFree; ++i)
        {
            if (data[i] != nullptr)
            {
                data[i] = nullptr;
                --effectiveSize;
            }
        }
        firstFree = newSize;
    }

    void** oldData = data;
    maxSize = newSize;
    if (newSize != 0)
    {
        data = AllocBuffer24afc0(static_cast<std::size_t>(newSize) * sizeof(void*));
        for (std::uint32_t i = 0; i < firstFree; ++i)
        {
            data[i] = oldData[i];
        }
        for (std::uint32_t i = firstFree; i < maxSize; ++i)
        {
            data[i] = nullptr;
        }
    }
    else
    {
        data = nullptr;
    }
    FreeBuffer24afc0(oldData);
}
