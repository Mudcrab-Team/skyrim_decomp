// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESForm fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::HasPerk: GUESS(low); the static source container and original signature are unverified.
#pragma once
class BGSPerk;
class TESForm;

class ConditionFunctions
{
public:
    static bool HasPerk(TESForm* reference, BGSPerk* perk, void*, double* result);
};
