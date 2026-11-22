// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; reconstructed from the pinned image listing and community names
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x391b00 BGSIdleMarker::~BGSIdleMarker
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
#include "BGSIdleMarker.h"

BGSIdleMarker::~BGSIdleMarker()
{
}

// TODO body: RVA 0x391b80, 10 bytes, BGSIdleMarker::GetIgnoredBySandbox.
bool BGSIdleMarker::GetIgnoredBySandbox() const
{
    return (unknown60 >> 4) & 1;
}
