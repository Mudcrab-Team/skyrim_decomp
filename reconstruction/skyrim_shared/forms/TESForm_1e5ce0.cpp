// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1e5ce0 TESForm::Function1e5ce0
// Adapted bodies: none
#include "TESForm_1e5ce0.h"

// Writes the four bytes of a value as characters, then a terminator.
void TESForm::Function1e5ce0(int value, char* buffer, std::uint32_t size)
{
    if (buffer && size >= 5) {
        buffer[0] = static_cast<char>(value);
        buffer[1] = static_cast<char>(value >> 8);
        buffer[2] = static_cast<char>(value >> 16);
        buffer[3] = static_cast<char>(static_cast<std::uint32_t>(value) >> 24);
        buffer[4] = 0;
    }
}
