// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::GetIsEditorLocAlias: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
// 0x33a7b0 Condition::GetIsEditorLocAlias
#include "ConditionFunctions_33a7b0.h"
class TESObjectREFR; class TESQuest; class BGSLocation;
extern thread_local TESQuest* conditionQuest;
extern thread_local bool conditionLoggingEnabled;
extern BGSLocation* GetLocationAlias(TESQuest*, unsigned int);
extern bool LocationContainsReference(BGSLocation*, TESObjectREFR*, bool);
extern void* conditionLogger;
extern const char editorAliasLogFormat[];
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetIsEditorLocAlias(TESObjectREFR* reference, unsigned int alias, void*, double* result)
{
    *result = 0.0;
    if (conditionQuest) {
        BGSLocation* location = GetLocationAlias(conditionQuest, alias);
        if (reference && location && LocationContainsReference(location, reference, true)) *result = 1.0;
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, editorAliasLogFormat, *result);
    return true;
}
