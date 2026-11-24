// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3f2490 TESTopicInfo::SetAltered
// Adapted bodies: TESTopicInfo::SetAltered follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/testopicinfo.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/testopicinfo.cpp:866
#include "TESTopicInfo_3f2490.h"

static bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1u) != 0;
}

void TESTopicInfo::SetAltered(bool a_set)
{
    if (!TestBit(formFlags, 14) && a_set && TestBit(formFlags, 3)) {
        TESTopic* owner = parentTopic;
        if (owner) {
            owner->SetAltered(true);
        }
    }
    TESForm::SetAltered(a_set);
}
