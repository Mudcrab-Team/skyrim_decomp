// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1c8520 BGSStoryManagerNodeBase::QConditions
// 0x5360f0 BGSStoryManagerNodeBase::InitializeData
#include "BGSStoryManagerNodeBase.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

// RVA 0x536120, 80 bytes
void BGSStoryManagerNodeBase::ClearData()
{
    TESForm::ClearData();
    conditions.Clear();
    if (!IsDataHandlerBusy(TESDataHandler::singleton) && TestBit(formFlags, 3) && parent != nullptr) {
        BranchRemoveChild(parent, this, 0);
    }
}

// RVA 0x1c7260, 93 bytes
// Near-miss: near-miss/0x1c7260.cpp

TESCondition* BGSStoryManagerNodeBase::QConditions()
{
    return &conditions;
}

void BGSStoryManagerNodeBase::InitializeData()
{
    TESForm::InitializeData();
    parent          = nullptr;
    previousSibling = nullptr;
    maxQuests       = 0;
    flags.nodeFlags = 0;
    flags.questFags = 0;
}
