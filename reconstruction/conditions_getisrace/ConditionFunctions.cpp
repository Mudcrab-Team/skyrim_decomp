// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESObjectREFR, TESNPC, TESRace and form fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetIsRace: GUESS(low); the static source container and original signature are unverified.
// 0x333790 Condition::GetIsRace
#include "ConditionFunctions.h"
#include "../fo4b4c_686600/Actor.h"
extern void* conditionLogger;
extern const char raceLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetIsRace(TESObjectREFR* reference, TESForm* parameter, void*, double* result)
{
    *result = 0.0;
    TESNPC* npc = nullptr;
    if (reference && reference->data.objectReference->formType == 0x2b) npc = static_cast<TESNPC*>(reference->data.objectReference);
    TESRace* race = nullptr;
    if (parameter && parameter->formType == 0x0e) race = reinterpret_cast<TESRace*>(parameter);
    double value = 0.0;
    if (npc && race && npc->race == race) { value = 1.0; *result = value; }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, raceLogFormat, value);
    return true;
}
