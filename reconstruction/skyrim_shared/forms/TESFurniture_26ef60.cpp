// Source exposure: mixed (pinned-image observations; community declarations; permitted sibling game code).
// Code origin: adapted from the anonymous permitted game-code sibling
// SPDX-License-Identifier: LicenseRef-Author-Permission
// 0x26ef60 TESFurniture::GetEntryPointFlags
// Cookbook: 0x26ef60 35
// Adapted bodies: TESFurniture::GetEntryPointFlags from fo4-private@1b765c70, author-permission
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESFurniture.cpp:287
// TESFurniture::GetEntryPointFlags: SIBLING(fo4-private@1b765c70, author-permission)
#include "TESFurniture_26ef60.h"

std::uint32_t TESFurniture::GetEntryPointFlags(std::uint32_t entryPoint) const
{
    std::uint32_t result = 0;
    bool found = false;
    for (std::uint32_t index = 0; index < count && !found; ++index) {
        if (entryPointDataArray[index].entryPoint == entryPoint) {
            result = entryPointDataArray[index].disabledEntryPoints;
            found = true;
        }
    }
    return result;
}
