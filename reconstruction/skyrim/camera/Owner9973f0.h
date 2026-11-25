// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: Stamped as a twin of matched 0x8f60a0 (skyrim/camera/FreeCameraState): source copied, names replaced by placeholders.
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/FreeCameraState.cpp:25
// Function9973f0, Owner9973f0: GUESS(low) STANDIN
#pragma once
#include "FreeCameraState.h"

class Owner9973f0
{
public:
    void Function9973f0(NiPoint3& value) const;
private:
    std::uint64_t unknown00[6];
    unsigned char padTwin30[48];
    NiPoint3 translation;
};
