// Origin: original reconstruction; declarations informed by CommonLibSSE-NG include/RE/N/NiObject.h and class hints.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendTransformInterpolator, NiBlendInterpolator: STANDIN EXE_RTTI
// IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
class NiObject; class NiStream;
class NiBlendInterpolator { public: bool IsEqual(NiObject* object); };
class NiBlendTransformInterpolator : public NiBlendInterpolator { public: bool IsEqual(NiObject* object); };
