// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; declarations informed by CommonLibSSE-NG.
// NiBSplineTransformInterpolator names and signatures: GUESS(low)
// NiBSplineTransformInterpolator, NiBSplineInterpolator, NiStream, RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiBSplineInterpolator, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf7b460 NiBSplineTransformInterpolator::RegisterStreamables
#include "NiBSplineTransformInterpolator_f7b460.h"
bool NiBSplineTransformInterpolator::RegisterStreamables(NiStream& stream)
{
    if (NiBSplineInterpolator::RegisterStreamables(stream)) return true; return false;
}
