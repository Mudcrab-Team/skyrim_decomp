// Build: sse-steam-1-7-104; RVA 0x3308c0; 173 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// ActorValueOwner::GetActorValue and actor layout: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted in ValueActor.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetActorValue: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
#include "Actor.h"
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
