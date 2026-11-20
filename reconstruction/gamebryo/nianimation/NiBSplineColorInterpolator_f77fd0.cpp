// Origin: original reconstruction; declarations informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// NiBSplineColorInterpolator names and signatures: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf77fd0 NiBSplineColorInterpolator::RegisterStreamables

#include "NiBSplineColorInterpolator_f77fd0.h"

bool NiBSplineColorInterpolator::RegisterStreamables(NiStream& stream) { if (NiBSplineInterpolator::RegisterStreamables(stream)) return true; return false; }
