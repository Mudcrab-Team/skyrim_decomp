// Build: sse-steam-1-7-104; RVA 0x33a230; 127 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::HasRefType: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
class TESObjectREFR; class BGSLocationRefType;
extern BGSLocationRefType* GetReferenceType(TESObjectREFR*);
extern void* conditionLogger;
extern const char refTypeLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::HasRefType(TESObjectREFR* reference, BGSLocationRefType* type, void*, double* result)
{
    *result = 0.0;
    if (reference && type && GetReferenceType(reference) == type) *result = 1.0;
    if (conditionLoggingEnabled) LogCondition(conditionLogger, refTypeLogFormat, *result);
    return true;
}
