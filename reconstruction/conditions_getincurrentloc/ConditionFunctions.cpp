// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInCurrentLoc: GUESS(low); the static source container and original signature are unverified.
// 0x33a490 Condition::GetInCurrentLoc
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
