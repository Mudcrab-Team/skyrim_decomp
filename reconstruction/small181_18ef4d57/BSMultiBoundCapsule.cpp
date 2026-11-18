// Origin: original reconstruction; declarations informed by CommonLibSSE-NG include/RE/N/NiObject.h and class hints.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSMultiBoundCapsule, BSMultiBoundShape: STANDIN EXE_RTTI
// RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x1002550 BSMultiBoundCapsule::RegisterStreamables
#include "BSMultiBoundCapsule.h"
bool BSMultiBoundCapsule::RegisterStreamables(NiStream& stream) { if (BSMultiBoundShape::RegisterStreamables(stream)) return true; return false; }
