// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4e04b0 PathingCell::Func8
#include "PathingCell.h"
bool PathingCell::IsAttached()
{
    TESObjectCELL* cell = GetCell();
    return cell && cell->cellState == 7;
}
