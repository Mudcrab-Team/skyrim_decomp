// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x2717b0 TESLevCharacter::InitItemImpl
#include "TESLevCharacter.h"

// Body done: RVA 0x2717b0, 64 bytes, TESLevCharacter::InitItemImpl. The flag test guards the
// whole initialisation; the last call is a tail call in the target.
void TESLevCharacter::InitItemImpl()
{
    if (!TestBit(formFlags, 3)) {
        InitLeveledListState(unknown30, this);
        InitModelTextureSwapState(unknown58, this);
        ResetOwnerState(this, true);
    }
}
