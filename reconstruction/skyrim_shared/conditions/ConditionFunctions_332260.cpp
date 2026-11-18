// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESQuest::data, QUEST_DATA::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetQuestCompleted: GUESS(low); the static source container and original signature are unverified.
// 0x332260 Condition::GetQuestCompleted
#include "ConditionFunctions_332260.h"
#include "../quest/TESQuest_332260.h"
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
