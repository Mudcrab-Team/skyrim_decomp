// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// GrenadeProjectile::GetCollisionGroup: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/GrenadeProjectile.cpp:147
// bhkCollisionFilter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/bhkCollisionFilter.h, include/RE/H/hkpCollisionFilter.h and its public base declarations.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7ec850 GrenadeProjectile::GetCollisionGroup
#include "GrenadeProjectile_7ec850.h"
unsigned GrenadeProjectile::GetCollisionGroup() const { bhkCollisionFilter* filter = collisionFilter; unsigned next = (filter->nextSystemGroup + 1) & 0xffff; filter->nextSystemGroup = next; if (!next) filter->nextSystemGroup = next = 10; return next; }
