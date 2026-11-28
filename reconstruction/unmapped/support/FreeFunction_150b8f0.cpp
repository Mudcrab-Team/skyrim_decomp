// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Function150b8f0, treated as adapted: shaped like NiTArray::SetSize in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00bc0000_o2.cpp:7759
// SPDX-License-Identifier: CC0-1.0
// 0x150b8f0 Function150b8f0
#include "FreeFunction_150b8f0.h"

// Resizes arr's backing pointer buffer to newSize, clearing truncated slots and zeroing new slots.
void Function150b8f0(PtrArray_150b8f0* arr, std::uint32_t newSize)
{
    if (newSize == arr->maxSize) {
        return;
    }

    if (newSize < arr->size) {
        for (std::uint16_t i = static_cast<std::uint16_t>(newSize); i < arr->size; ++i) {
            if (arr->data[i] != nullptr) {
                arr->data[i] = nullptr;
                --arr->count;
            }
        }
        arr->size = static_cast<std::uint16_t>(newSize);
    }

    void** oldData = arr->data;
    arr->maxSize = static_cast<std::uint16_t>(newSize);

    if (newSize > 0) {
        arr->data = static_cast<void**>(
            Alloc_150b8f0(static_cast<std::size_t>(arr->maxSize) * sizeof(void*)));
        for (std::uint16_t i = 0; i < arr->size; ++i) {
            arr->data[i] = oldData[i];
        }
        for (std::uint16_t i = arr->size; i < arr->maxSize; ++i) {
            arr->data[i] = nullptr;
        }
    } else {
        arr->data = nullptr;
    }

    Free_150b8f0(oldData);
}
