// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESObjectREFR::HasKeywordHelper: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declaration in included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::HasKeyword: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
#pragma once
class BGSKeyword;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool HasKeyword(TESObjectREFR* reference, BGSKeyword* keyword, void*, double* result);
};
