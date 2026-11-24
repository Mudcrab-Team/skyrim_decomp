// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: Stamped as a twin of matched 0x5d6a40 (skyrim_shared/tempeffects/ModelReferenceEffect_5d6a40): source copied, names replaced by placeholders.
// GetAttached: Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:291
// flags: STANDIN GUESS(low)
// Get3D: Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:57
// unknown00, artObject: STANDIN GUESS(low)
// Function267450, Owner267450: GUESS(low) STANDIN
#pragma once
#include "ModelReferenceEffect_5d6a40.h"

class Owner267450
{
public:
    NiAVObject* Function267450() const;
    bool GetAttached() const;
private:
    std::uint64_t unknown00[25];
    NiAVObject* artObject;
    std::uint32_t flags;
};

