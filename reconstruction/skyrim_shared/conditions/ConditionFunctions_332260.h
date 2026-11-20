// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESQuest::data, QUEST_DATA::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions: GUESS(low); the static source container and original signature are unverified.
// ConditionFunctions::GetQuestCompleted: OBSERVED; conditionFunction pointer (+0x40) paired with functionName (+0x00) in the image's 0x50-byte SCRIPT_FUNCTION table (confirmed across >20 entries).
#pragma once
class TESObjectREFR;
class TESQuest;

class ConditionFunctions
{
public:
    static bool GetQuestCompleted(TESObjectREFR*, TESQuest* quest, void*, double* result);
};
