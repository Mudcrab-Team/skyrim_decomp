// Origin: original reconstruction; class declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESNPC, TESActorBase, UnClone3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// ClearClonedState: GUESS(low)
#pragma once
class TESActorBase { public: void UnClone3D(); };
class TESNPC : public TESActorBase { public: void UnClone3D(); void ClearClonedState(); };
