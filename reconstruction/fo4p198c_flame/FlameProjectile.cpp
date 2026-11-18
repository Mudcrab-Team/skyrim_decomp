// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// FlameProjectile::Handle3DLoaded: SIBLING(fo4-private@1b765c70, author-permission); adapted flag update.
// FlameProjectile::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted state reset.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/FlameProjectile.cpp:107
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/FlameProjectile.cpp:99
// 0x7eb430 FlameProjectile::Handle3DLoaded
// 0x7eb240 FlameProjectile::Revert
#include "FlameProjectile.h"
void FlameProjectile::Handle3DLoaded() { flags = (flags & 0xffffffccu) | 8u; }
void FlameProjectile::Revert(BGSLoadFormBuffer* buffer) {
    Projectile::Revert(buffer);
    timers.expirationTimer = 0;
    timers.coneAngle = 0;
}
