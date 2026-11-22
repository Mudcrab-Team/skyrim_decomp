// Source exposure: mixed (pinned image listing and labelled declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing with labelled declarations.
// Adapted bodies: none.
// kFirstSkillActorValue: OBSERVED
// 0x3b2b10 TESClass::GetMaximumTrainingLevel
// 0x3b2890 TESClass::InitializeData
// 0x3b2ae0 TESClass::Function3b2ae0
#include "TESClass.h"

namespace {
constexpr std::uint32_t kFirstSkillActorValue = 6;
}

// g_defaultTrainingLevel: GUESS(low)
extern float g_defaultTrainingLevel;
// g_defaultTrainingSkill: GUESS(low)
extern std::uint32_t g_defaultTrainingSkill;

std::uint8_t TESClass::GetMaximumTrainingLevel()
{
    return maximumTrainingLevel;
}

void TESClass::InitializeData()
{
    volatile std::uint64_t* const zeroes = &unk50;
    zeroes[0] = 0;
    zeroes[1] = 0;
    zeroes[2] = 0;
    zeroes[3] = 0;
    unk70 = 0;
    trainingLevel = g_defaultTrainingLevel;
    trainingSkill = g_defaultTrainingSkill;
}
// Convert the stored training skill index to an actor value.
std::uint32_t TESClass::Function3b2ae0() const
{
    return trainingSkillIndex + kFirstSkillActorValue;
}
