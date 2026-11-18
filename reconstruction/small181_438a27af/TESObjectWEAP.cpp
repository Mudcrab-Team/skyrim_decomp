// Origin: original reconstruction; class name from CommonLibSSE-NG include/RE/T/TESObjectWEAP.h.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectWEAP: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// QueryValue, CalculateValue: GUESS(low)
// 0x28c120 TESObjectWEAP::QueryValue
#include "TESObjectWEAP.h"
int TESObjectWEAP::QueryValue() { return static_cast<int>(CalculateValue(nullptr, this, nullptr)); }
