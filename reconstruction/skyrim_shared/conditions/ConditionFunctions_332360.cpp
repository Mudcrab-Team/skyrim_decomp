// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetStageDone: GUESS(low); the static source container and original signature are unverified.
// 0x332360 Condition::GetStageDone
#include "ConditionFunctions_332360.h"
class TESObjectREFR;
class TESQuest;
extern bool QuestStageDone(TESQuest*, unsigned short);
extern void* conditionLogger;
extern const char stageDoneLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetStageDone(TESObjectREFR*, TESQuest* quest, unsigned short stage, double* result)
{
    *result = 0.0;
    if (quest && QuestStageDone(quest, stage)) *result = 1.0;
    if (conditionLoggingEnabled) LogCondition(conditionLogger, stageDoneLogFormat, *result);
    return true;
}
