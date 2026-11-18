// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESForm::formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInWorldspace: GUESS(low); the static source container and original signature are unverified.
// 0x333580 Condition::GetInWorldspace
#include "ConditionFunctions_333580.h"
#include "../forms/TESForm_1467c0.h"
extern TESForm* GetReferenceWorldspace(TESForm*);
extern int FindFormInList(TESForm*, TESForm*);
extern void* conditionLogger;
extern const char worldspaceLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetInWorldspace(TESForm* reference, TESForm* parameter, TESForm* other, double* result)
{
    *result = 0.0;
    TESForm* selected = other;
    if (!(other && static_cast<unsigned char>(static_cast<unsigned char>(other->formType) - 0x3d) <= 9)) selected = reference;
    if (parameter) {
        if (parameter->formType == static_cast<FormType>(0x47)) {
            TESForm* world = GetReferenceWorldspace(selected);
            if (world && world == parameter) *result = 1.0;
        } else if (parameter->formType == static_cast<FormType>(0x5b)) {
            TESForm* world = GetReferenceWorldspace(selected);
            if (world && FindFormInList(parameter, world) != -1) *result = 1.0;
        }
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, worldspaceLogFormat, *result);
    return true;
}
