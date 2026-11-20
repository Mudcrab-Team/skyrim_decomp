// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::GetKeywordDataForLocation: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
// 0x33ae20 Condition::GetKeywordDataForLocation
#include "ConditionFunctions_33ae20.h"
class TESObjectREFR; class BGSLocation; class BGSKeyword;
extern float GetLocationKeywordData(BGSLocation*, BGSKeyword*);
extern void* conditionLogger;
extern const char keywordDataLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetKeywordDataForLocation(TESObjectREFR*, BGSLocation* location, BGSKeyword* keyword, double* result)
{
    *result = 0.0;
    double value = 0.0;
    if (location) { value = GetLocationKeywordData(location, keyword); *result = value; }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, keywordDataLogFormat, value);
    return true;
}
