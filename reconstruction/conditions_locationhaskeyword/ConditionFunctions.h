// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// BGSLocation, BGSKeywordForm::HasKeyword: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::LocationHasKeyword: GUESS(low); the static source container and original signature are unverified.
#pragma once
class BGSKeyword;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool LocationHasKeyword(TESObjectREFR* reference, BGSKeyword* keyword, void*, double* result);
};
