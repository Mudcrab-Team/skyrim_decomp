// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x747b30 PlayerCharacter::GetCurrent3D
// Adapted bodies: PlayerCharacter::GetCurrent3D follows fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:589 (author-permission); written from the Skyrim listing, offsets and slots checked there
#include "PlayerCharacter_747b30.h"

NiAVObject* PlayerCharacter::GetCurrent3D() const
{
    if (!Is3rdPersonVisible()) {
        return firstPerson3D;
    }
    return TESObjectREFR::Get3D2();
}
