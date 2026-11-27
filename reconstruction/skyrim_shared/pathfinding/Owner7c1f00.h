// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: original declarations and the cited sibling adaptation. Stamped as a twin of matched 0x4f76b0 (skyrim_shared/pathfinding/PathingRequestFlyOrbit): source copied, names replaced by placeholders.
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyOrbit.cpp:67
// Function7c1f00, Owner7c1f00: GUESS(low) STANDIN
#pragma once
#include "PathingRequestFlyOrbit.h"

class Owner7c1f00 {
public:
    unsigned int GetType() const;
    void SetOrbitPoint(const NiPoint3& a_point);
    NiPoint3& Function7c1f00(NiPoint3& a_out) const;

private:
    std::uint8_t unknown00[0xf4];
    NiPoint3 orbitPoint;
};
