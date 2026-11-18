// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// TESObject and TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations in included header.
// TESObjectREFR data offset: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/T/TESObjectREFR.h.
// names: GUESS(low); names and signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionFunctions, ConditionFunctions::GetIsVoiceType: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESForm;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetIsVoiceType(TESObjectREFR* reference, TESForm* parameter, void*, double* result);
};
