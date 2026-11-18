// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESObjectREFR::IsDead: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declaration in DeadActor.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetDead: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESForm;

class ConditionFunctions
{
public:
    static bool GetDead(TESForm* reference, void*, void*, double* result);
};
