// Source exposure: mixed (community headers and pinned-image analysis).
// Code origin: original reconstruction; declarations adapted from the pinned MIT community headers.
// Drafted by gpt-6.1-sol, Engineers p105 and p115. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x266030 BGSProjectile::UnClone3D
// 0x266430 BGSProjectile::GetActivateText
// 0x2656c0 BGSProjectile::InitializeData
#include "BGSProjectile.h"
inline bool TestBit(std::uint32_t flags,std::uint32_t bit) { return ((flags>>bit)&1)!=0; }
void BGSProjectile::UnClone3D(TESObjectREFR* ref) { UnCloneProjectile(this,ref); if(ref && ((projectileData.flagsAndType&0x7f0000)==0x40000 || !static_cast<Projectile*>(ref)->inventoryEntry || !*static_cast<void**>(static_cast<Projectile*>(ref)->inventoryEntry))) RemoveProjectileClone(this,ref); }
bool BGSProjectile::GetActivateText(TESObjectREFR* ref,BSString& text) { std::int32_t count=ref?ProjectileCount(&ref->extraList):0; if(TestBit(projectileData.flagsAndType,6)) { bool crime=ProjectileCrime(ref); if(count>1) { const char* action=TakeProjectileText; if(crime) action=StealProjectileText; auto* name=ProjectileName(ref); FormatProjectileText(&text,"%s\n%s (%i)",action,name,count); } else { const char* action=TakeProjectileText; if(crime) action=StealProjectileText; auto* name=ProjectileName(ref); FormatProjectileText(&text,"%s\n%s",action,name); } return true; } return false; }

