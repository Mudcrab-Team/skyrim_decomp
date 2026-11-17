// Build: sse-steam-1-7-104; RVA 0x33a490; 126 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInCurrentLoc: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
class TESObjectREFR; class BGSLocation;
extern bool LocationContainsReference(BGSLocation*, TESObjectREFR*, bool);
extern void* conditionLogger;
extern const char locationLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetInCurrentLoc(TESObjectREFR* reference, BGSLocation* location, void*, double* result)
{
    *result = 0.0;
    if (location && reference && LocationContainsReference(location, reference, false)) *result = 1.0;
    if (conditionLoggingEnabled) LogCondition(conditionLogger, locationLogFormat, *result);
    return true;
}
