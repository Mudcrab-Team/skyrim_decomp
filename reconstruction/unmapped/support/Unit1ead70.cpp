// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1ead70 Unit1ead70::BuildReplacedPath1ead70
// Adapted bodies: none
#include "Unit1ead70.h"

// Copies the object path into the 260-byte buffer and replaces the file extension after the last dot.
void Unit1ead70::BuildReplacedPath1ead70(char* a_buffer) const
{
    strcpy_s(a_buffer, 260, GetPath());
    char* dot = strrchr(a_buffer, '.');
    if (dot) {
        strcpy_s(dot, 260 - static_cast<std::size_t>(dot - a_buffer), g_extension1ead70);
    }
}
