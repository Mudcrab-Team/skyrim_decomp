// Build: sse-steam-1-7-104; RVA 0x3394e0; 130 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESForm fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::HasPerk: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
#include "../fo4p198c_bound/TESForm.h"
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
