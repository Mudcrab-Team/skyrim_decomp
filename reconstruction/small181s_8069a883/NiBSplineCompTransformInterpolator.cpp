// Origin: original reconstruction; declarations informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// NiBSplineCompTransformInterpolator names and signatures: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf79af0 NiBSplineCompTransformInterpolator::RegisterStreamables

#include "NiBSplineCompTransformInterpolator.h"

bool NiBSplineCompTransformInterpolator::RegisterStreamables(NiStream& stream) { if (NiBSplineTransformInterpolator::RegisterStreamables(stream)) return true; return false; }
