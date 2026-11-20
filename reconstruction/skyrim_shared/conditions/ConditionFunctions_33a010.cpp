// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESObjectREFR::HasKeywordHelper: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declaration in included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::HasKeyword: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
// 0x33a010 Condition::HasKeyword
#include "ConditionFunctions_33a010.h"
#include "../refs/TESObjectREFR_2ef670.h"
extern void* conditionLogger;
extern const char keywordLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::HasKeyword(TESObjectREFR* reference, BGSKeyword* keyword, void*, double* result)
{
    *result = 0.0;
    if (reference && keyword && reference->HasKeywordHelper(keyword)) *result = 1.0;
    if (conditionLoggingEnabled) LogCondition(conditionLogger, keywordLogFormat, *result);
    return true;
}
