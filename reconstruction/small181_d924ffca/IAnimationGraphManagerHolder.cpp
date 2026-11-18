// Origin: original reconstruction, declarations adapted from CommonLibSSE-NG include/RE/I/IAnimationGraphManagerHolder.h.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IAnimationGraphManagerHolder, SetGraphVariableBool, SetGraphVariableInt, SetGraphVariableFloat: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetBoolImpl, SetIntImpl, SetFloatImpl: GUESS(low)
// 0x553560 IAnimationGraphManagerHolder::SetGraphVariableBool
#include "IAnimationGraphManagerHolder.h"
bool IAnimationGraphManagerHolder::SetGraphVariableBool(const BSFixedString& name, bool value) { return SetBoolImpl(name, value); }
bool IAnimationGraphManagerHolder::SetGraphVariableInt(const BSFixedString& name, std::int32_t value) { return SetIntImpl(name, value); }
bool IAnimationGraphManagerHolder::SetGraphVariableFloat(const BSFixedString& name, float value) { return SetFloatImpl(name, value); }
