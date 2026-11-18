// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x1e88f0 TESLeveledList::GetMultCalc
// 0x1e8930 TESLeveledList::GetUseAll
// 0x1e8850 TESLeveledList::InitializeDataComponent
// 0x1e8880 TESLeveledList::GetChanceNone
#include "TESLeveledList.h"

void TESLeveledList::InitializeDataComponent()
{
    entries = nullptr;
    chanceNone = 0;
    llFlags = 0;
    numEntries = 0;
    unk13 = 0;
    unk18 = nullptr;
    chanceGlobal = nullptr;
}

std::uint8_t TESLeveledList::GetChanceNone()
{
    if (chanceGlobal) {
        return static_cast<std::uint8_t>(chanceGlobal->value);
    }
    return chanceNone;
}

bool TESLeveledList::GetMultCalc()
{
    return TestBit(llFlags, 1);
}

bool TESLeveledList::GetUseAll()
{
    return TestBit(llFlags, 2);
}

std::int32_t TESLeveledList::GetLevDifferenceMax()
{
    return 0;
}
