// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::GetCurrentTime: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
// 0x330b90 Condition::GetCurrentTime
#include "ConditionFunctions_330b90.h"
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
