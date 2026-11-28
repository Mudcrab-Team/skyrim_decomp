// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x243ed0 Obj243ed0::GetValue
// Adapted bodies: none
#include "Obj243ed0.h"

// Return a table entry when row and column indices are within bounds.
float Obj243ed0::GetValue(std::int32_t row, std::int32_t col) const
{
    if (rows && col >= 0 && col < 16)
    {
        std::int32_t idx = row - baseRow;
        if (idx >= 0 && idx < rowCount)
        {
            return rows[idx][col];
        }
    }
    return 0.0f;
}
