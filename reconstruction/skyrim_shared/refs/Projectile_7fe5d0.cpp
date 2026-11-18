// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// Projectile::GetLinearVelocity: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/Projectile.cpp:643
// Projectile, Projectile::GetLinearVelocity: GUESS(low)
// Projectile fields: STANDIN GUESS(low)
// 0x7fe5d0 Projectile::GetLinearVelocity
#include "Projectile_7fe5d0.h"
void Projectile::GetLinearVelocity(Point3& out) const { out.x = velocity.x; out.y = velocity.y; out.z = velocity.z; }
