// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1e5c60 TESForm::Function1e5c60
// Adapted bodies: none
#include "TESForm_1e5c60.h"

// Looks up a form type index by name; zero when absent.
std::uint32_t TESForm::Function1e5c60(const char* a_name)
{
    std::uint32_t result = 0;
    if (a_name) {
        for (std::uint32_t i = 0; i < 0x8A && result == 0; ++i) {
            if (_stricmp(a_name, gFormTypeTable[i].name) == 0) {
                result = i;
            }
        }
    }
    return result;
}
