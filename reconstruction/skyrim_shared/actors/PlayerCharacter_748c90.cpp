// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x748c90 PlayerCharacter::GetCurrentBiped
// Adapted bodies: PlayerCharacter::GetCurrentBiped follows fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:576 (author-permission); written from the Skyrim listing, offsets and slots checked there
#include "PlayerCharacter_748c90.h"

const BipedAnimPtr& PlayerCharacter::GetCurrentBiped() const
{
    return GetBiped1(!Is3rdPersonVisible());
}
