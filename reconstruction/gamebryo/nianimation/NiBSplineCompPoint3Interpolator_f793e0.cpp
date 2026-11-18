// Origin: original reconstruction; declarations informed by CommonLibSSE-NG include/RE/N/NiObject.h and class hints.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBSplineCompPoint3Interpolator, NiBSplinePoint3Interpolator: STANDIN EXE_RTTI
// RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0xf793e0 NiBSplineCompPoint3Interpolator::RegisterStreamables
#include "NiBSplineCompPoint3Interpolator_f793e0.h"
bool NiBSplineCompPoint3Interpolator::RegisterStreamables(NiStream& stream) { if (NiBSplinePoint3Interpolator::RegisterStreamables(stream)) return true; return false; }
