// Origin: original reconstruction; declarations informed by CommonLibSSE-NG include/RE/N/NiObject.h and class hints.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBSplineFloatInterpolator, NiBSplineInterpolator: STANDIN EXE_RTTI
// RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0xf7a500 NiBSplineFloatInterpolator::RegisterStreamables
#include "NiBSplineFloatInterpolator_f7a500.h"
bool NiBSplineFloatInterpolator::RegisterStreamables(NiStream& stream) { if (NiBSplineInterpolator::RegisterStreamables(stream)) return true; return false; }
