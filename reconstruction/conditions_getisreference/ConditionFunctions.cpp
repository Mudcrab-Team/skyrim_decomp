// Build: sse-steam-1-7-104; RVA 0x334180; 127 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESForm::formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetIsReference: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
#include "../fo4p198c_bound/TESForm.h"
extern void* conditionLogger;
extern const char referenceLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetIsReference(TESForm* reference, TESForm* parameter, void*, double* result)
{
    *result = 0.0;
    TESForm* other = nullptr;
    if (parameter && static_cast<unsigned char>(static_cast<unsigned char>(parameter->formType) - 0x3d) <= 9) other = parameter;
    double value = 0.0;
    if (reference && other && reference == other) { value = 1.0; *result = value; }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, referenceLogFormat, value);
    return true;
}
