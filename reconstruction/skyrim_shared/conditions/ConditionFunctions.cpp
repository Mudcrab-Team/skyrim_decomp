// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// ActorValueOwner::GetActorValue and actor layout: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted in ValueActor.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetActorValue: GUESS(low); the static source container and original signature are unverified.
// 0x3308c0 Condition::GetActorValue
#include "ConditionFunctions.h"
#include "../actors/Actor_3308c0.h"
extern const char* ActorValueName(unsigned int);
class ConditionLogger { public: void Print(const char*, ...); };
extern ConditionLogger* conditionLogger;
extern const char actorValueLogFormat[];
extern thread_local bool conditionLoggingEnabled;
bool ConditionFunctions::GetActorValue(TESObjectREFR* reference, void* actorValueParameter, void*, double* result)
{
    TESObjectREFR* actor = reference ? (reference->formType == 0x3e ? reference : nullptr) : nullptr;
    if (actor) {
        unsigned int actorValue = static_cast<unsigned int>(reinterpret_cast<unsigned long long>(actorValueParameter));
        double value = static_cast<Actor*>(actor)->GetActorValue(actorValue);
        *result = value;
        if (conditionLoggingEnabled) {
            ConditionLogger* logger = conditionLogger;
            logger->Print(actorValueLogFormat, ActorValueName(actorValue), value);
        }
    }
    return true;
}
