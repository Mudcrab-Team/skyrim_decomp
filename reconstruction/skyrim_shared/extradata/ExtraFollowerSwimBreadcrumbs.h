// Source exposure: mixed (local binary analysis and public names).
// 0x1872c0 compared function
// Code origin: original; the body is written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// ExtraFollowerSwimBreadcrumbs: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Function1872c0, field28: GUESS(low)
#pragma once
#include <cstdint>

class ExtraFollowerSwimBreadcrumbs
{
public:
    virtual std::uint32_t GetType() const;
    void* Function1872c0() const;

    std::uint8_t pad08[0x20];  // 08
    void* field28;  // 28
};
