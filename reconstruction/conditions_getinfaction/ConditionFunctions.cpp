// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// Actor::IsInFaction: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); slot declaration in FactionActor.h.
// TESForm fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations in FactionActor.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInFaction: GUESS(low); the static source container and original signature are unverified.
// 0x3339f0 Condition::GetInFaction
#include "ConditionFunctions.h"
#include "Actor.h"
extern TESObjectREFR* cachedFactionReference;
extern TESFaction* cachedFaction;
extern float cachedFactionResult;
extern void* conditionLogger;
extern const char factionLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetInFaction(TESObjectREFR* reference, TESForm* parameter, void*, double* result)
{
    *result = 0.0;
    TESFaction* faction = nullptr;
    if (parameter && parameter->formType == 11) faction = reinterpret_cast<TESFaction*>(parameter);
    double value;
    if (reference == cachedFactionReference && faction == cachedFaction) {
        value = cachedFactionResult;
        *result = value;
    } else {
        Actor* actor = reference ? (reference->formType == 0x3e ? static_cast<Actor*>(reference) : nullptr) : nullptr;
        if (!actor) return true;
        if (actor->IsInFaction(faction)) *result = 1.0;
        value = *result;
        cachedFactionReference = reference;
        cachedFaction = faction;
        cachedFactionResult = static_cast<float>(value);
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, factionLogFormat, value);
    return true;
}
