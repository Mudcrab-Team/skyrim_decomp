// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESForm::formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInWorldspace: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESForm;

class ConditionFunctions
{
public:
    static bool GetInWorldspace(TESForm* reference, TESForm* parameter, TESForm* other, double* result);
};
