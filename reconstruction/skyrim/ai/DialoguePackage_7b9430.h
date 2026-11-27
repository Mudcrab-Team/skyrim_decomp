// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// DialoguePackage: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// DialoguePackage::Function7b9430: GUESS(low)
// DialoguePackage::unknown0, DialoguePackage::value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class DialoguePackage
{
public:
    std::uint32_t* Function7b9430(std::uint32_t* output);
    std::uint8_t unknown0[232];
    std::uint32_t value;
};
static_assert(offsetof(DialoguePackage, value) == 232, "field offset");
