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
#pragma once
class TESObjectREFR;
class TESQuest;

class ConditionFunctions
{
public:
    static bool GetQuestCompleted(TESObjectREFR*, TESQuest* quest, void*, double* result);
};
