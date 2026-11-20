// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names, generator representation, and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::GetRandomPercent: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
// 0x334340 Condition::GetRandomPercent
#include "ConditionFunctions_334340.h"
struct RandomGenerator {
    unsigned int seed;
    unsigned int state[624];
    unsigned int position;
    bool initialized;
    RandomGenerator();
    ~RandomGenerator();
    unsigned int Next(unsigned int);
};
extern void* conditionLogger;
extern const char randomLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetRandomPercent(void*, void*, void*, double* result)
{
    static RandomGenerator random;
    double value = random.Next(100);
    *result = value;
    if (conditionLoggingEnabled) LogCondition(conditionLogger, randomLogFormat, value);
    return true;
}
