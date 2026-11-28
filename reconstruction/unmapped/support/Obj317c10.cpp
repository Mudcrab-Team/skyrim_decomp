// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x317c10 Obj317c10::~Obj317c10
// Adapted bodies: none
#include "Obj317c10.h"

// Guess: release the owned heap buffer on destruction.
Obj317c10::~Obj317c10()
{
    FreeBuffer317c10(m_buffer);
}
