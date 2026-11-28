// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x318440 Obj318440::~Obj318440
// Adapted bodies: none
#include "Obj318440.h"

// Guess: release the owned heap buffer on destruction.
Obj318440::~Obj318440()
{
    FreeBuffer318440(m_buffer);
}
