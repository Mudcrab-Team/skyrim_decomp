// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESObjectREFR, TESNPC and form fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// GetActorBase: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); local simplified accessor.
// ConditionFunctions, ConditionFunctions::GetPCIsSex: GUESS(low); the static source container and original signature are unverified.
// 0x333c30 Condition::GetPCIsSex
#include "ConditionFunctions_333c30.h"
#include "../actors/Actor_686600.h"
extern TESObjectREFR* playerCharacter;
extern int GetNPCSex(TESNPC*);
extern void* conditionLogger;
extern const char playerSexLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
// Base record of a reference as an NPC; empty when the reference has no base record.
static TESNPC* GetActorBase(TESObjectREFR* reference)
{
    TESForm* base = reference->data.objectReference;
    return base ? static_cast<TESNPC*>(base) : nullptr;
}
bool ConditionFunctions::GetPCIsSex(TESObjectREFR*, void* sexParameter, void*, double* result)
{
    // The condition parameter slot is pointer-wide and carries the sex value in its low bits.
    int sex = static_cast<int>(reinterpret_cast<long long>(sexParameter));
    TESObjectREFR* player = playerCharacter;
    *result = 0.0;
    if (player) {
        if (player->data.objectReference->formType == 0x2b) {
            TESNPC* npc = GetActorBase(player);
            if (npc && GetNPCSex(npc) == sex) *result = 1.0;
        }
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, playerSexLogFormat, *result);
    return true;
}
