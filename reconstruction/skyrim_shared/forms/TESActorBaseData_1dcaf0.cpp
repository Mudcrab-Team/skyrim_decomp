// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1dcaf0 TESActorBaseData::GetTemplateUseFlag
// Adapted bodies: TESActorBaseData::GetTemplateUseFlag follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesactorbasedata.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesactorbasedata.cpp:107
#include "TESActorBaseData_1dcaf0.h"

bool TESActorBaseData::GetTemplateUseFlag(int a_flag)
{
    if (a_flag >= 0) {
        const auto flagMask = static_cast<std::uint16_t>(1u << a_flag);
        const bool usesTemplate = (actorData.templateUseFlags & flagMask) != 0;
        return usesTemplate;
    }
    return true;
}
