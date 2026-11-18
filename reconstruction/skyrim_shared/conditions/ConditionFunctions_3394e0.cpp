// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESForm fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::HasPerk: GUESS(low); the static source container and original signature are unverified.
// 0x3394e0 Condition::HasPerk
#include "ConditionFunctions_3394e0.h"
#include "../../fo4p198c_bound/TESForm.h"
class TESObjectREFR; class BGSPerk;
extern bool ActorHasPerk(TESObjectREFR*, BGSPerk*);
extern void* conditionLogger;
extern const char perkLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::HasPerk(TESForm* reference, BGSPerk* perk, void*, double* result)
{
    *result = 0.0;
    TESForm* actor = reference ? (reference->formType == static_cast<FormType>(0x3e) ? reference : nullptr) : nullptr;
    if (actor) {
        int hasPerk = ActorHasPerk(reinterpret_cast<TESObjectREFR*>(actor), perk);
        if (conditionLoggingEnabled) LogCondition(conditionLogger, perkLogFormat, hasPerk);
        if (hasPerk) *result = 1.0;
    }
    return true;
}
