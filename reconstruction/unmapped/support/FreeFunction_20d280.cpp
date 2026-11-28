// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x20d280 Function20d280
// Adapted bodies: none
#include "FreeFunction_20d280.h"

// Returns the string length, subtracting 13 when it begins with the 4-character prefix.
std::uint32_t Function20d280(const FixedString20d280* str)
{
    std::uint32_t length = GetStringLength20d280(str);
    if (str->data != nullptr) {
        if (_strnicmp(str->data, g_prefix20d280, 4) == 0) {
            length -= 13;
        }
    }
    return length;
}
