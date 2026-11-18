// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// GrenadeProjectile::TurnOff, GrenadeProjectile::IsPermanent: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/GrenadeProjectile.cpp:53
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/GrenadeProjectile.cpp:127
// GrenadeProjectile, Projectile, TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/G/GrenadeProjectile.h, include/RE/P/Projectile.h, include/RE/T/TESObjectREFR.h, include/RE/E/ExtraDataList.h, include/RE/N/NiTransform.h and include/RE/B/BSSoundHandle.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7ec630 GrenadeProjectile::TurnOff
// 0x7ec700 GrenadeProjectile::IsPermanent
#include "GrenadeProjectile_7ec630.h"
bool GrenadeProjectile::TurnOff(Actor* actor, bool silent) { bool result = Projectile::TurnOff(actor, silent); Process3D(); return result; }
bool GrenadeProjectile::IsPermanent() { return IsMine() || Projectile::IsPermanent(); }
