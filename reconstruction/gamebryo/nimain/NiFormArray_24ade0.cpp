// Source exposure: mixed (the pinned image listing; sibling shape).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/NiFormArray.cpp:56
// 0x24ade0 NiFormArray::InsertArrayAt
#include "NiFormArray_24ade0.h"
#include <cstring>

void NiFormArray::InsertArrayAt(std::uint32_t a_index, NiFormArray* a_array)
{
    Compact();
    a_array->Compact();
    std::uint32_t newSize = a_array->m_uiSize + m_uiSize;
    if (m_uiMaxSize < newSize) {
        SetSize(newSize + m_uiGrowBy);
    }
    std::memmove(&m_pBase[a_index + a_array->m_uiSize], &m_pBase[a_index], 8LL * (m_uiSize - a_index));
    TESForm** pBase = m_pBase;
    m_uiSize += a_array->m_uiSize;
    m_uiESize = m_uiSize;
    std::memcpy(&pBase[a_index], a_array->m_pBase, 8LL * a_array->m_uiSize);
}
