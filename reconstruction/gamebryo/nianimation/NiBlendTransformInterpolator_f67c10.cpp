// Origin: original reconstruction; declarations informed by CommonLibSSE-NG include/RE/N/NiObject.h and class hints.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendTransformInterpolator, NiBlendInterpolator: STANDIN EXE_RTTI
// IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0xf67c10 NiBlendTransformInterpolator::IsEqual
#include "NiBlendTransformInterpolator_f67c10.h"
bool NiBlendTransformInterpolator::IsEqual(NiObject* object) { if (NiBlendInterpolator::IsEqual(object)) return true; return false; }
