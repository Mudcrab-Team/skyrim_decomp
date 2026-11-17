// Build: sse-steam-1-7-104; RVA 0x333c30; 143 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESObjectREFR, TESNPC and form fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetPCIsSex: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
#include "../fo4b4c_686600/Actor.h"
extern TESObjectREFR* playerCharacter;
extern int GetNPCSex(TESNPC*);
extern void* conditionLogger;
extern const char playerSexLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetPCIsSex(TESObjectREFR*, void* sexParameter, void*, double* result)
{
    // The condition parameter slot is pointer-wide; the target copies the whole slot before using its low 32 bits.
    int sex = static_cast<int>(reinterpret_cast<long long>(sexParameter));
    TESObjectREFR* player = playerCharacter;
    *result = 0.0;
    if (player) {
        if (player->data.objectReference->formType == 0x2b) {
            TESNPC* npc = static_cast<TESNPC*>(player->data.objectReference);
            if (npc && GetNPCSex(npc) == sex) *result = 1.0;
        }
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, playerSexLogFormat, *result);
    return true;
}
