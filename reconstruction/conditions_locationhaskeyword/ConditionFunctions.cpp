// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// BGSLocation, BGSKeywordForm::HasKeyword: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::LocationHasKeyword: GUESS(low); the static source container and original signature are unverified.
// 0x33a2c0 Condition::LocationHasKeyword
#include "ConditionFunctions.h"
#include "BGSLocation.h"
class TESObjectREFR;
extern BGSLocation* GetCurrentLocation(TESObjectREFR*);
extern void* conditionLogger;
extern const char locationKeywordLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::LocationHasKeyword(TESObjectREFR* reference, BGSKeyword* keyword, void*, double* result)
{
    *result = 0.0;
    if (reference) {
        BGSLocation* location = GetCurrentLocation(reference);
        if (location && keyword && location->HasKeyword(keyword)) *result = 1.0;
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, locationKeywordLogFormat, *result);
    return true;
}
