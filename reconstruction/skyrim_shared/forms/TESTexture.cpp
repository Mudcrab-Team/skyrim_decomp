// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x146760 TESTexture::GetMaxAllowedSize
// 0x1f2b20 Leaf1f2b20::Invoke
// 0x1f3320 TESTexture::GetDefaultPath
#include "TESTexture.h"

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
