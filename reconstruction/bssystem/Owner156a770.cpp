// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build. Stamped as a twin of matched 0x156aaf0 (bssystem/NiMemStream_156a9e0): source copied, names replaced by placeholders.
// 0x156a770 Owner156a770::Function156a770
#include "Owner156a770.h"
#include <cstring>

// FreeStreamBuffer_156a770: GUESS(low) STANDIN
void FreeStreamBuffer_156a770(void* buffer);

Owner156a770::~Owner156a770()
{
    if (!externalBuffer && !released) {
        FreeStreamBuffer_156a770(buffer);
    }
}

// guess: same compiled code as matched 0x156aaf0 apart from relocated fields; its role here is not established.
std::uint32_t Owner156a770::Function156a770(void* destination, std::uint32_t count)
{
    const auto available = length - position;
    if (count > available) {
        count = available;
    }
    std::memcpy(destination, buffer + position, count);
    position += count;
    return count;
}
