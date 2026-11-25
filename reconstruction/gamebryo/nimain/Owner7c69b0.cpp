// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// Code origin: Stamped as a twin of matched 0xfdc610 (gamebryo/nimain/BSOcclusionShape): source copied, names replaced by placeholders.
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x7c69b0 Owner7c69b0::~Owner7c69b0
// CI hash: 0x7c69b0 ??_GOwner7c69b0@@UEAAPEAXI@Z
#include "Owner7c69b0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
Owner7c69b0::Owner7c69b0()
{
}

// deleting destructor. The target does the NiRefObject cleanup itself, so keep this empty
// definition and the constructor: the inline base destructors in the header make the compiler
// produce the same body.
Owner7c69b0::~Owner7c69b0()
{
}
