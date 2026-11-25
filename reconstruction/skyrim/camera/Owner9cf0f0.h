// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: Stamped as a twin of matched 0x5dc480 (skyrim/camera/OwnedCameraEffectController): source copied, names replaced by placeholders.
// EffectRotatesWithCamera: Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:155
// unknown00, inheritRotation: STANDIN GUESS(low)
// Function9cf0f0, Owner9cf0f0: GUESS(low) STANDIN
#pragma once
#include "OwnedCameraEffectController.h"

class Owner9cf0f0
{
public:
    bool Function9cf0f0() const;
private:
    std::uint64_t unknown00[6];
    unsigned char padTwin30[8];
    bool inheritRotation;
};
