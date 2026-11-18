// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// GrenadeProjectile::Revert, GrenadeProjectile::SaveGame, GrenadeProjectile::LoadGame, GrenadeProjectile::FinishLoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/GrenadeProjectile.cpp:120
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/GrenadeProjectile.cpp:87
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/GrenadeProjectile.cpp:96
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/GrenadeProjectile.cpp:111
// GrenadeProjectile, Projectile, TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/G/GrenadeProjectile.h, include/RE/P/Projectile.h, include/RE/T/TESObjectREFR.h, include/RE/E/ExtraDataList.h, include/RE/N/NiTransform.h and include/RE/B/BSSoundHandle.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7ec820 GrenadeProjectile::Revert
// 0x7ec740 GrenadeProjectile::SaveGame
// 0x7ec780 GrenadeProjectile::LoadGame
// 0x7ec7d0 GrenadeProjectile::FinishLoadGame
#include "GrenadeProjectile_7ec740.h"
void GrenadeProjectile::Revert(LoadBuffer* b) { Projectile::Revert(b); collisionGroupReset = false; }
void GrenadeProjectile::SaveGame(SaveBuffer* b) { Projectile::SaveGame(b); decalGroup->SaveGame(b); }
void GrenadeProjectile::LoadGame(LoadBuffer* b) { Projectile::LoadGame(b); decalGroup->LoadGame(b); }
void GrenadeProjectile::FinishLoadGame(LoadBuffer* b) { Projectile::FinishLoadGame(b); if (decalGroup) decalGroup->FinishLoadGame(); if ((unsigned char)(flags >> 8) & 1) Track(); }
