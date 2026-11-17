// Build: sse-steam-1-7-104; RVA 0x332260; 114 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESQuest::data, QUEST_DATA::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetQuestCompleted: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
#include "TESQuest.h"
class TESObjectREFR;
extern void* conditionLogger;
extern const char questCompletedLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
static bool TestBit(unsigned a_flags, unsigned a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}
bool ConditionFunctions::GetQuestCompleted(TESObjectREFR*, TESQuest* quest, void*, double* result)
{
    *result = 0.0;
    double value = 0.0;
    if (quest && TestBit(quest->data.flags, 1)) { value = 1.0; *result = value; }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, questCompletedLogFormat, value);
    return true;
}
