// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Form and TESGlobal fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/T/TESForm.h and include/RE/T/TESGlobal.h.
// names: GUESS(low); names and signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionFunctions, ConditionFunctions::GetGlobalValue: GUESS(low); the static source container and original signature are unverified.
#pragma once
struct Form;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetGlobalValue(TESObjectREFR*, Form* parameter, void*, double* result);
};
