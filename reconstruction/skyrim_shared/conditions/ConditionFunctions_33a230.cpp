// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::HasRefType: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
// 0x33a230 Condition::HasRefType
#include "ConditionFunctions_33a230.h"
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
