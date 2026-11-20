// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7ea200 FlameProjectile::Constructor
// 0x7eb1c0 FlameProjectile::LoadGame
// 0x7eb150 FlameProjectile::SaveGame
// 0x7ea260 FlameProjectile::Slot164
// 0x7eb510 FlameProjectile::~FlameProjectile
#include "FlameProjectile.h"
FlameProjectile::FlameProjectile() { formType=static_cast<FormType>(0x43); timers.expirationTimer=0; timers.coneAngle=0; }
void FlameProjectile::LoadGame(BGSLoadFormBuffer* a_buf) { Projectile::LoadGame(a_buf); BGSLoadGameBuffer_LoadDataEndian(a_buf,&timers.expirationTimer,4,4); return BGSLoadGameBuffer_LoadDataEndian(a_buf,&timers.coneAngle,4,4); }
void FlameProjectile::SaveGame(BGSSaveFormBuffer* a_buf) { Projectile::SaveGame(a_buf); BGSSaveGameBuffer_SaveDataEndian(a_buf,&timers.expirationTimer,4,4,0); BGSSaveGameBuffer_SaveDataEndian(a_buf,&timers.coneAngle,4,4,0); }
std::uint8_t FlameProjectile::Slot164() const { return 1; }

