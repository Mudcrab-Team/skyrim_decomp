// Origin: original reconstruction; class declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PathingCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// PathWorld, PathCell: STANDIN GUESS(low)
// GetWorld, GetCell: GUESS(low)
// 0x4e0460 PathingCell::GetWorld
#include "PathingCell_4e0460.h"
PathWorld* PathingCell::GetWorld() { auto* cell = GetCell(); if (cell) return cell->GetWorld(); return nullptr; }
