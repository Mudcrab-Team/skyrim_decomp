// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xcd85b0 BSXAudio2Audio::~BSXAudio2Audio
// Adapted bodies: none
#include "BSXAudio2Audio.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
BSXAudio2Audio::BSXAudio2Audio()
{
}

// The complete destructor stores the vftable and releases nothing.
BSXAudio2Audio::~BSXAudio2Audio()
{
}
