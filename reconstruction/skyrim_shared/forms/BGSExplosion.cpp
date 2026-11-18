// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x260a30 BGSExplosion::InitializeData
// 0x261660 BGSExplosion::~BGSExplosion
#include "BGSExplosion.h"
BGSExplosion::BGSExplosion() {}
BGSExplosion::~BGSExplosion() {}
void BGSExplosion::InitializeData() { data.soundLevel=1; data.light=nullptr; data.sound1=nullptr; data.sound2=nullptr; data.impactDataSet=nullptr; data.impactPlacedObject=nullptr; data.force=0; data.damage=0; data.radius=0; data.imageSpaceRadius=0; data.verticalOffsetMult=0; data.flags=0; data.spawnProjectile=nullptr; }

