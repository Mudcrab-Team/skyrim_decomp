// Origin: original reconstruction, declarations adapted from CommonLibSSE-NG include/RE/I/IAnimationGraphManagerHolder.h.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IAnimationGraphManagerHolder, SetGraphVariableBool, SetGraphVariableInt, SetGraphVariableFloat: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetBoolImpl, SetIntImpl, SetFloatImpl: GUESS(low)
#pragma once
#include <cstdint>
class BSFixedString;
class IAnimationGraphManagerHolder
{
public:
 bool SetGraphVariableBool(const BSFixedString& name, bool value);
 bool SetGraphVariableInt(const BSFixedString& name, std::int32_t value);
 bool SetGraphVariableFloat(const BSFixedString& name, float value);
 bool SetBoolImpl(const BSFixedString& name, const bool& value);
 bool SetIntImpl(const BSFixedString& name, const std::int32_t& value);
 bool SetFloatImpl(const BSFixedString& name, const float& value);
};
