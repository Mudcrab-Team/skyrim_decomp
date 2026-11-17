// Build: sse-steam-1-7-104; RVA 0x33a640; 165 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInCurrentLocAlias: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
class TESObjectREFR; class TESQuest; class BGSLocation;
extern thread_local TESQuest* conditionQuest;
extern thread_local bool conditionLoggingEnabled;
extern BGSLocation* GetLocationAlias(TESQuest*, unsigned int);
extern bool LocationContainsReference(BGSLocation*, TESObjectREFR*, bool);
extern void* conditionLogger;
extern const char currentAliasLogFormat[];
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetInCurrentLocAlias(TESObjectREFR* reference, unsigned int alias, void*, double* result)
{
    *result = 0.0;
    if (conditionQuest) {
        BGSLocation* location = GetLocationAlias(conditionQuest, alias);
        if (reference && location && LocationContainsReference(location, reference, false)) *result = 1.0;
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, currentAliasLogFormat, *result);
    return true;
}
