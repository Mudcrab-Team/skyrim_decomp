// Build: sse-steam-1-7-104; RVA 0x33a2c0; 144 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// BGSLocation, BGSKeywordForm::HasKeyword: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::LocationHasKeyword: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
#include "BGSLocation.h"
class TESObjectREFR;
extern BGSLocation* GetCurrentLocation(TESObjectREFR*);
extern void* conditionLogger;
extern const char locationKeywordLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::LocationHasKeyword(TESObjectREFR* reference, BGSKeyword* keyword, void*, double* result)
{
    *result = 0.0;
    if (reference) {
        BGSLocation* location = GetCurrentLocation(reference);
        if (location && keyword && location->HasKeyword(keyword)) *result = 1.0;
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, locationKeywordLogFormat, *result);
    return true;
}
