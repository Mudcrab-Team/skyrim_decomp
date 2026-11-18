// Origin: original reconstruction informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// NiTransformController names and signatures: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
// NiTransformController, NiSingleInterpController: EXE_RTTI
// NiObject, NiTransformController::IsEqual, NiSingleInterpController::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiObject;
class NiSingleInterpController { public: bool IsEqual(NiObject*); };
class NiTransformController : public NiSingleInterpController { public: bool IsEqual(NiObject*); };
