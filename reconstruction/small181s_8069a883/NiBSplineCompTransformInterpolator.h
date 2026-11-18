// Origin: original reconstruction informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// NiBSplineCompTransformInterpolator names and signatures: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
// NiBSplineCompTransformInterpolator, NiBSplineTransformInterpolator: EXE_RTTI
// NiStream, NiBSplineCompTransformInterpolator::RegisterStreamables, NiBSplineTransformInterpolator::RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiStream;
class NiBSplineTransformInterpolator { public: bool RegisterStreamables(NiStream&); };
class NiBSplineCompTransformInterpolator : public NiBSplineTransformInterpolator { public: bool RegisterStreamables(NiStream&); };
