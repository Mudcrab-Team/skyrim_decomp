// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// SummonCreatureEffect, SummonCreatureEffect::SetLocation: GUESS(low)
// SummonCreatureEffect fields: STANDIN GUESS(low)
// Point3: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct Point3 { float x, y, z; };
class SummonCreatureEffect {
public:
    void SetLocation(const Point3& value);
private:
    std::uint8_t pad[0x90]; Point3 location;
};
