// Source exposure: mixed (pinned-image observations; community declarations; permitted sibling game code).
// Code origin: adapted from the anonymous permitted game-code sibling
// SPDX-License-Identifier: LicenseRef-Author-Permission
// 0x26edc0 TESFurniture::Function26edc0
// Cookbook: 0x26edc0 35
// Adapted bodies: TESFurniture::Function26edc0 from fo4-private@1b765c70, author-permission
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESFurniture.cpp:287
// TESFurniture::Function26edc0: GUESS(low); placeholder method name
#include "TESFurniture_26edc0.h"

BGSKeyword* TESFurniture::Function26edc0(std::uint32_t entryPoint) const
{
    BGSKeyword* result = nullptr;
    bool found = false;
    for (std::uint32_t index = 0; index < count && !found; ++index) {
        if (entryPointDataArray[index].entryPoint == entryPoint) {
            result = entryPointDataArray[index].keyword;
            found = true;
        }
    }
    return result;
}
