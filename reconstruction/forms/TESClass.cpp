// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x3b2b10 TESClass::GetMaximumTrainingLevel
// 0x3b2890 TESClass::InitializeData
#include "TESClass.h"

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
