// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xf05970 NiTexture::Unk_28
// 0xef3ea0 NiTexture::~NiTexture
#include "NiTexture.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiTexture::NiTexture()
{
}

// TODO body: RVA 0xf05970, 18 bytes, NiTexture::Unk_28.
void NiTexture::Unk_28(std::uint32_t& a_arg1, std::uint32_t& a_arg2, std::uint32_t& a_arg3, std::uint32_t& a_arg4)
{
    a_arg1 = 0;
    a_arg2 = 0;
    a_arg3 = 0;
    a_arg4 = 0;
}

// TODO body: RVA 0xef3ea0, 52 bytes, NiTexture::~NiTexture; compared as the scalar deleting
// destructor. If the target calls a separate destructor, keep only the declaration and delete this
// definition (cookbook rule 18).
NiTexture::~NiTexture()
{
}
