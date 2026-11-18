// Code origin: IsMissileProjectile and IsGrenadeProjectile bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x7f92a0 Projectile::IsMissileProjectile
// 0x7f92b0 Projectile::IsGrenadeProjectile
#include "Projectile.h"
bool Projectile::IsMissileProjectile() const { return false; }
bool Projectile::IsGrenadeProjectile() const { return false; }
