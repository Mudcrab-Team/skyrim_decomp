// Origin: original reconstruction; class declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESNPC, TESActorBase, UnClone3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// ClearClonedState: GUESS(low)
// 0x3c28b0 TESNPC::UnClone3D
#include "TESNPC.h"
void TESNPC::UnClone3D() { TESActorBase::UnClone3D(); ClearClonedState(); }
