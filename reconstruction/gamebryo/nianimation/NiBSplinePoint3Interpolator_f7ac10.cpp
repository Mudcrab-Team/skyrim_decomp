// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; declarations informed by CommonLibSSE-NG.
// NiBSplinePoint3Interpolator names and signatures: GUESS(low)
// NiBSplinePoint3Interpolator, NiBSplineInterpolator, NiStream, RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiBSplineInterpolator, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf7ac10 NiBSplinePoint3Interpolator::RegisterStreamables
#include "NiBSplinePoint3Interpolator_f7ac10.h"
bool NiBSplinePoint3Interpolator::RegisterStreamables(NiStream& stream)
{
    if (NiBSplineInterpolator::RegisterStreamables(stream)) return true; return false;
}
