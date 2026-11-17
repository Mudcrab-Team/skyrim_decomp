// Build: sse-steam-1-7-104; RVA 0x334340; 200 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names, generator representation, and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetRandomPercent: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
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
