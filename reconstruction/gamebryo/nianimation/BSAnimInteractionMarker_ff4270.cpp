// Source exposure: mixed (pinned-image observations and public declarations).
// Code origin: original hand-written reconstruction; no adapted body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSAnimInteractionMarker: CRASHLOGGER_PDB(59818@2026.10.24)
// NiExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CopyMembers: OBSERVED; named reference and copy operation.
// markerX, markerY, markerZ, markerFlags, reserved: GUESS(low); copied fields have unresolved semantics.
// 0xff4270 BSAnimInteractionMarker::CopyMembers
#include "BSAnimInteractionMarker_ff4270.h"
void BSAnimInteractionMarker::CopyMembers(BSAnimInteractionMarker* destination, void* cloningProcess)
{
    NiExtraData::CopyMembers(destination, cloningProcess);
    destination->markerX = markerX;
    destination->markerY = markerY;
    destination->markerZ = markerZ;
    destination->markerFlags = markerFlags;
}
