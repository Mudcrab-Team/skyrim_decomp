// Source exposure: mixed (sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/NiFormArray.cpp:56
// NiFormArray, NiFormArray::InsertArrayAt: SIBLING(fo4-private@1b765c70, author-permission)
// Compact, SetSize, m_pBase, m_uiMaxSize, m_uiSize, m_uiESize, m_uiGrowBy: GUESS(medium); the names the sibling body uses for these members
// TESForm: STANDIN SIBLING(fo4-private@1b765c70, author-permission)
#pragma once

#include <cstdint>

class TESForm;

class NiFormArray
{
public:
    virtual ~NiFormArray();  // 00

    void Compact();
    void SetSize(std::uint32_t a_size);
    void InsertArrayAt(std::uint32_t a_index, NiFormArray* a_array);  // compared: 0x24ade0

    TESForm** m_pBase;  // 08
    std::uint32_t m_uiMaxSize;  // 10
    std::uint32_t m_uiSize;  // 14
    std::uint32_t m_uiESize;  // 18
    std::uint32_t m_uiGrowBy;  // 1C
};
static_assert(sizeof(NiFormArray) == 0x20, "NiFormArray size");
