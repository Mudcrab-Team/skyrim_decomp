// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetStage: GUESS(low); the static source container and original signature are unverified.
// 0x3322e0 Condition::GetStage
#include "ConditionFunctions_3322e0.h"
class TESObjectREFR;
class TESQuest;
extern unsigned int GetQuestStage(TESQuest*);
extern void* conditionLogger;
extern const char conditionLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetStage(TESObjectREFR*, TESQuest* quest, void*, double* result)
{
    *result = 0.0;
    double value = 0.0;
    if (quest) {
        value = static_cast<float>(GetQuestStage(quest));
        *result = value;
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, conditionLogFormat, value);
    return true;
}
