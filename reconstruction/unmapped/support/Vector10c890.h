// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Vector10c890, DestroyRange10c890: GUESS(low) STANDIN
#pragma once

struct Vector10c890
{
    void Clear();  // compared: 0x10c890

    void* first;  // 0x00
    void* last;   // 0x08
    void* end;    // 0x10
};

void DestroyRange10c890(void* a_first, void* a_last, Vector10c890* a_allocator);
