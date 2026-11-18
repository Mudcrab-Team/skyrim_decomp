// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// Actor::IsInFaction: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); slot declaration in FactionActor.h.
// TESForm fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations in FactionActor.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInFaction: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESForm;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool GetInFaction(TESObjectREFR* reference, TESForm* parameter, void*, double* result);
};
