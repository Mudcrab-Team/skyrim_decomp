// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x3ac610 BGSSceneActionPackage::Unk_0B
// 0x3ac2b0 BGSSceneActionPackage::Unk_11
#include "BGSSceneActionPackage.h"

void BGSSceneActionPackage::Unk_0B()
{
    RawAt<std::uint32_t>(this, 0x20) = 0;
    BGSSceneAction::Unk_0B();
}

void BGSSceneActionPackage::Unk_11()
{
    if (!Unk_05()) {
        flags14 |= 0x2;
    }
}
