// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetKeywordDataForLocation: GUESS(low); the static source container and original signature are unverified.
// 0x33ae20 Condition::GetKeywordDataForLocation
#include "ConditionFunctions.h"
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
