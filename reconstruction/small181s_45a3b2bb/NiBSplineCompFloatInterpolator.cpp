// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; declarations informed by CommonLibSSE-NG.
// NiBSplineCompFloatInterpolator names and signatures: GUESS(low)
// NiBSplineCompFloatInterpolator, NiBSplineFloatInterpolator, NiStream, RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiBSplineFloatInterpolator, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf78d70 NiBSplineCompFloatInterpolator::RegisterStreamables
#include "NiBSplineCompFloatInterpolator.h"
bool NiBSplineCompFloatInterpolator::RegisterStreamables(NiStream& stream)
{
    if (NiBSplineFloatInterpolator::RegisterStreamables(stream)) return true; return false;
}
