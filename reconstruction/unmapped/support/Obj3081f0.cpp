// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj3081f0::GetColor, treated as adapted: shaped like TESWeather::GetCloudColor in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/sky/sky.cpp:1283
// SPDX-License-Identifier: CC0-1.0
// 0x3081f0 Obj3081f0::GetColor
#include "Obj3081f0.h"

// Guess: look up a color in the row/column table or return a column-specific default.
std::uint32_t Obj3081f0::GetColor(std::int32_t a_row, std::int32_t a_col) const
{
    std::uint32_t color;
    if (a_col == 1)
    {
        color = 0x9B9B9Bu;
    }
    else if (a_col == 3)
    {
        color = 0x1C140Fu;
    }
    else if (a_col == 0)
    {
        color = 0x5B4B46u;
    }
    else
    {
        color = 0x6C5953u;
    }

    if (m_rowCount > 0)
    {
        const std::int32_t row = a_row < m_rowCount ? a_row : 0;
        color = m_colors[row][a_col];
    }
    return color;
}
