// Near miss: 5.0 alignment distance | control-flow
// Source exposure: mixed
// 0x637e10 BGSLoadFormBuffer::ReadEncodedValue
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLoadFormBuffer, buffer, bufferPosition: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReadEncodedValue: GUESS(low); reads a value with an embedded width tag
#include "include/637e10/BGSLoadFormBuffer_637e10.h"
#include <cstring>

// Copy the unaligned tagged value and advance by its selected storage width.
std::uint32_t BGSLoadFormBuffer::ReadEncodedValue()
{
    const char* cursor = static_cast<const char*>(buffer) + bufferPosition;
    switch (*cursor & 3)
    {
    case 0:
    {
        std::uint8_t value;
        std::memcpy(&value, cursor, sizeof(value));
        bufferPosition += 1;
        return value >> 2;
    }
    case 1:
    {
        std::uint16_t value;
        std::memcpy(&value, cursor, sizeof(value));
        bufferPosition += 2;
        return value >> 2;
    }
    case 2:
    {
        std::uint32_t value;
        std::memcpy(&value, cursor, sizeof(value));
        bufferPosition += 4;
        return value >> 2;
    }
    default:
        return 0;
    }
}
