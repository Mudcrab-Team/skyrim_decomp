// Build: sse-steam-1-7-104; RVA 0x330b90; 94 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetCurrentTime: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
class TESObjectREFR; class Calendar;
extern Calendar* calendar;
extern float CurrentHour(Calendar*);
extern void* conditionLogger;
extern const char currentTimeLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetCurrentTime(TESObjectREFR*, void*, void*, double* result)
{
    double value = CurrentHour(calendar);
    *result = value;
    if (conditionLoggingEnabled) LogCondition(conditionLogger, currentTimeLogFormat, value);
    return true;
}
