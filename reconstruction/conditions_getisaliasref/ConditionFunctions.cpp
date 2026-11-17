// Build: sse-steam-1-7-104; RVA 0x33a6f0; 171 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetIsAliasRef: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
struct RefHandle { unsigned int value; };
class TESObjectREFR;
class TESQuest;
extern RefHandle* GetAliasHandle(TESQuest*, RefHandle*, unsigned int);
extern RefHandle* GetReferenceHandle(TESObjectREFR*, RefHandle*);
extern thread_local TESQuest* conditionQuest;
extern thread_local bool conditionLoggingEnabled;
extern void* conditionLogger;
extern const char aliasLogFormat[];
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetIsAliasRef(TESObjectREFR* reference, void* aliasParameter, void*, double& result)
{
    TESQuest* quest = conditionQuest;
    result = 0.0;
    if (quest) {
        RefHandle aliasHandle, referenceHandle;
        GetAliasHandle(quest, &aliasHandle, static_cast<unsigned int>(reinterpret_cast<unsigned long long>(aliasParameter)));
        if (reference) {
            if (GetReferenceHandle(reference, &referenceHandle)->value == aliasHandle.value) result = 1.0;
        }
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, aliasLogFormat, result);
    return true;
}
