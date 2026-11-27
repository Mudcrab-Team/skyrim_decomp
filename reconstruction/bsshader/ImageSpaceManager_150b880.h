// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiTPrimitiveArray::SetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niintegersextradata_o2_variant.cpp:205
// The CrashLogger PDB name here is ImageSpaceManager::RegisterEffect; the body only sets an array element, so it is written as the array method.
// ImageSpaceManager, ImageSpaceManager::effects: CRASHLOGGER_PDB(59818@2026.10.24)
// ImageSpaceEffect, NiTPrimitiveArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetAt, data, capacity, size, numElements, growthSize: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceEffect;

template <class T>
class NiTPrimitiveArray
{
public:
    virtual ~NiTPrimitiveArray();

    void SetAt(std::uint32_t a_index, const T& a_element);  // compared: 0x150b880

    T* data;                  // 08
    std::uint16_t capacity;   // 10
    std::uint16_t size;       // 12
    std::uint16_t numElements;// 14
    std::uint16_t growthSize; // 16
};
static_assert(sizeof(NiTPrimitiveArray<ImageSpaceEffect*>) == 0x18, "NiTPrimitiveArray size");

class ImageSpaceManager
{
public:
    NiTPrimitiveArray<ImageSpaceEffect*> effects;
};
