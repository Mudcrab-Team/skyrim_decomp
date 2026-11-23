// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESObjectREFR::IsDead: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declaration in DeadActor.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::GetDead: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
// 0x3316b0 Condition::GetDead
#include "ConditionFunctions_3316b0.h"
#include "../actors/Actor_3316b0.h"
extern void* conditionLogger;
extern const char deadLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetDead(TESForm* reference, void*, void*, double* result)
{
    *result = 0.0;
    TESForm* actor = reference ? (reference->formType == 0x3e ? reference : nullptr) : nullptr;
    if (actor && static_cast<TESObjectREFR*>(actor)->IsDead(true)) *result = 1.0;
    if (conditionLoggingEnabled) LogCondition(conditionLogger, deadLogFormat, *result);
    return true;
}
