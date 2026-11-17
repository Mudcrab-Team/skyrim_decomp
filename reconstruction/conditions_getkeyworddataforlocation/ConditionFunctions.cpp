// Build: sse-steam-1-7-104; RVA 0x33ae20; 111 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetKeywordDataForLocation: GUESS(low); the static source container and original signature are unverified.
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
