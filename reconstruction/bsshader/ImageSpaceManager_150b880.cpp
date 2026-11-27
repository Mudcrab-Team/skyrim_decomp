// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiTPrimitiveArray::SetAt as similar to the sibling bodies cited in the header (CC0-1.0); the draft states it was written from the pinned image listing.
// 0x150b880 NiTPrimitiveArray<ImageSpaceEffect*>::SetAt
#include "ImageSpaceManager_150b880.h"

template <class T>
void NiTPrimitiveArray<T>::SetAt(std::uint32_t a_index, const T& a_element)
{
    if (a_index >= size) {
        size = static_cast<std::uint16_t>(a_index + 1);
        if (a_element) {
            ++numElements;
        }
    } else if (a_element) {
        if (!data[a_index]) {
            ++numElements;
        }
    } else if (data[a_index]) {
        --numElements;
    }
    data[a_index] = a_element;
}

template class NiTPrimitiveArray<ImageSpaceEffect*>;
