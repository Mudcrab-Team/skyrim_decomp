// Source exposure: mixed (the listing of the pinned image; names from community declarations and the sibling used by the adapted body).
// Code origin: body adapted from the sibling function below; the base constructor and offsets checked against the listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/AI/BSSimpleScaleController.cpp:30
// 0x7383f0 BSSimpleScaleController::BSSimpleScaleController
#include "BSSimpleScaleController_7383f0.h"

// The controller starts active (bit 0 set) with the cycle-type bit cleared and every scale value zero.
BSSimpleScaleController::BSSimpleScaleController()
    : NiTimeController(), fStartScale(0.0f), fEndScale(0.0f), fEndTime(0.0f)
{
    flags |= 1;
    flags &= ~8;
}
