// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x1f30f0 TESTexture::Function1f30f0
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
#include "TESTexture.h"

bool TESTexture::Function1f30f0()
{
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this)) == 0x4E4F4349u;
}

// Body done: RVA 0x146760, 3 bytes, TESTexture::GetMaxAllowedSize.
std::uint32_t TESTexture::GetMaxAllowedSize()
{
    return 0;
}

// Body done: RVA 0x1f2b20, 3 bytes, TESTexture::ClearDataComponent.
void TESTexture::ClearDataComponent()
{
}

// Body done: RVA 0x1f3320, 8 bytes, TESTexture::GetDefaultPath.
const char* TESTexture::GetDefaultPath() const
{
    return "Textures\\";
}
