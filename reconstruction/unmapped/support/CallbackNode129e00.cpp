// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x129e00 CallbackNode129e00::~CallbackNode129e00
// Adapted bodies: none
#include "CallbackNode129e00.h"

// Recursively deletes the next callback node and destroys this node's callable.
CallbackNode129e00::~CallbackNode129e00()
{
    delete next;
}
