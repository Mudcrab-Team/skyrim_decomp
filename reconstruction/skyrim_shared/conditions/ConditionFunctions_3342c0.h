// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Form and TESGlobal fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/T/TESForm.h and include/RE/T/TESGlobal.h.
// names: GUESS(low); names and signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::GetGlobalValue: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
#pragma once
struct Form;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetGlobalValue(TESObjectREFR*, Form* parameter, void*, double* result);
};
