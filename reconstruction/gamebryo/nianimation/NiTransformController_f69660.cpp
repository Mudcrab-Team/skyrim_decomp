// Origin: original reconstruction; declarations informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// NiTransformController names and signatures: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf69660 NiTransformController::IsEqual

#include "NiTransformController_f69660.h"

bool NiTransformController::IsEqual(NiObject* object) { if (NiSingleInterpController::IsEqual(object)) return true; return false; }
