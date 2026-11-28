// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x244360 Obj244360::Serialize
// Adapted bodies: none
#include "Obj244360.h"

#include <cstring>

namespace
{
bool WriteU32(std::uint8_t*& cur, const std::uint8_t* end, std::uint32_t value)
{
    if (cur + sizeof(std::uint32_t) > end)
    {
        return false;
    }
    std::memcpy(cur, &value, sizeof(std::uint32_t));
    cur += sizeof(std::uint32_t);
    return true;
}
}  // namespace

// Serialize table metadata and row float arrays into a bounded output buffer.
bool Obj244360::Serialize(std::uint8_t* buffer, std::uint32_t bufferSize) const
{
    const std::uint8_t* end = buffer + bufferSize;
    std::uint8_t* cur = buffer;
    *cur++ = 2;
    if (!WriteU32(cur, end, rowCount))
    {
        return false;
    }
    if (!WriteU32(cur, end, unk04))
    {
        return false;
    }
    if (!WriteU32(cur, end, colCount))
    {
        return false;
    }

    std::int32_t totalCols = colCount;
    if (hasExtra)
    {
        totalCols += 17;
    }

    for (std::uint32_t i = 0; i < rowCount; ++i)
    {
        std::int32_t rowBytes = totalCols * 4;
        if (cur + rowBytes > end)
        {
            return false;
        }
        std::memcpy(cur, rows[i], rowBytes);
        cur += rowBytes;
    }
    return cur == end;
}
