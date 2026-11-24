// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3b6c80 TESIdleForm::ClearData
// Adapted bodies: TESIdleForm::ClearData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesidleform.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesidleform.cpp:55
#include "TESIdleForm_3b6c80.h"

static bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1u) != 0;
}

void TESIdleForm::ClearData()
{
    if (g_idleRegistrationEnabled && TestBit(formFlags, 3) && parentIdle) {
        parentIdle->UnregisterIdleForm(this);
    }
    conditions.Clear();
}
