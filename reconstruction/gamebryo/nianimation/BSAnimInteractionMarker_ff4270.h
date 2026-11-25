// Source exposure: mixed (pinned-image observations and public declarations).
// Code origin: original hand-written reconstruction; no adapted body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSAnimInteractionMarker: CRASHLOGGER_PDB(59818@2026.10.24)
// NiExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CopyMembers: OBSERVED; named reference and copy operation.
// markerX, markerY, markerZ, markerFlags, reserved: GUESS(low); copied fields have unresolved semantics.
// NiExtraData: STANDIN OBSERVED; minimal base layout and external call boundary.
// 0xff4270 BSAnimInteractionMarker::CopyMembers
#pragma once
#include <cstdint>
class NiExtraData {
public:
    void CopyMembers(NiExtraData* destination, void* cloningProcess);
    std::uint8_t reserved[0x18];
};
class BSAnimInteractionMarker : public NiExtraData {
public:
    void CopyMembers(BSAnimInteractionMarker* destination, void* cloningProcess);
    float markerX;
    float markerY;
    float markerZ;
    std::uint16_t markerFlags;
};
static_assert(sizeof(NiExtraData) == 0x18, "observed layout");
