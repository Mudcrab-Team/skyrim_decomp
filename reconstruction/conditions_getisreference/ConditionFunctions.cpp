// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESForm::formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetIsReference: GUESS(low); the static source container and original signature are unverified.
// 0x334180 Condition::GetIsReference
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
