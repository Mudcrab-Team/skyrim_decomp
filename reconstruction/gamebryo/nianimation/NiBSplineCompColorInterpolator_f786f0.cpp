// Origin: original reconstruction; declarations informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// NiBSplineCompColorInterpolator names and signatures: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf786f0 NiBSplineCompColorInterpolator::RegisterStreamables

#include "NiBSplineCompColorInterpolator_f786f0.h"

bool NiBSplineCompColorInterpolator::RegisterStreamables(NiStream& stream) { if (NiBSplineColorInterpolator::RegisterStreamables(stream)) return true; return false; }
