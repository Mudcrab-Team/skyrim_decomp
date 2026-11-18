// Origin: original reconstruction; class declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PathingCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// PathWorld, PathCell: STANDIN GUESS(low)
// GetWorld, GetCell: GUESS(low)
#pragma once
class PathWorld;
class PathCell { public: PathWorld* GetWorld(); };
class PathingCell { public: PathCell* GetCell(); PathWorld* GetWorld(); };
