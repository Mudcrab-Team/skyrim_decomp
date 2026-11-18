// Origin: original reconstruction informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// NiBSplineColorInterpolator names and signatures: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
// NiBSplineColorInterpolator, NiBSplineInterpolator: EXE_RTTI
// NiStream, NiBSplineColorInterpolator::RegisterStreamables, NiBSplineInterpolator::RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiStream;
class NiBSplineInterpolator { public: bool RegisterStreamables(NiStream&); };
class NiBSplineColorInterpolator : public NiBSplineInterpolator { public: bool RegisterStreamables(NiStream&); };
