// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// Projectile, Projectile::GetLinearVelocity: GUESS(low)
// Projectile fields: STANDIN GUESS(low)
// Point3: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct Point3 { float x, y, z; };
class Projectile {
public:
    void GetLinearVelocity(Point3& out) const;
private:
    std::uint8_t pad[0x104]; Point3 velocity;
};
