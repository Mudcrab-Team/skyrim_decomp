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
#pragma once
struct Point3 { float x,y,z; }; struct Matrix3 { float value[3][3]; }; struct Transform { Matrix3 rotation; Point3 translation; float scale; };
class Component { public: virtual ~Component(); };
class TESForm : public Component { public: void* files; unsigned formFlags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; };
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount, pad; };
class BSHandleRefObject : public NiRefObject {};
class EventSink { public: virtual ~EventSink(); };
class AnimationHolder { public: virtual ~AnimationHolder(); };
struct ObjectReference { void* object; Point3 angle, location; };
class BaseExtraList { public: virtual ~BaseExtraList(); void* data; void* presence; };
struct Lock { unsigned owner, count; };
struct ExtraDataList { BaseExtraList data; Lock lock; };
class TESObjectREFR : public TESForm, public BSHandleRefObject, public EventSink, public AnimationHolder { public: ObjectReference data; void* parentCell; void* loadedData; ExtraDataList extraList; unsigned long long unknown90; unsigned short refScale; signed char modelState; bool preDestroyed; unsigned pad9c; };
struct List { void* item; void* next; };
struct SoundHandle { unsigned id; bool success; unsigned char pad; unsigned short pad2; unsigned state; };
class LoadBuffer; class SaveBuffer;
class Projectile : public TESObjectREFR { public:
 List impacts; Transform transform; float unknownE4; void* phantom; Lock lock; Point3 velocity, linearVelocity; void* light; void* unknown118; void* actorCause; unsigned shooter, desiredTarget; SoundHandle sound, countdown; unsigned* unknown148; void* inventoryEntry; void* explosion; void* spell; unsigned castingSource, pad16c; void* effectSetting; void* projectileDBFiles; unsigned long long unknown180, unknown188; float power, speedMult, range, livingTime, weaponDamage, transparency, explosionTimer; unsigned unknown1ac; float unknown1b0, unknown1b4; void* weaponSource; void* ammoSource; float distanceMoved; unsigned unknown1cc; float scale; unsigned flags; bool unknown1d8, unknown1d9; unsigned char unknown1da[6];
 void Revert(LoadBuffer*); void SaveGame(SaveBuffer*); void LoadGame(LoadBuffer*); void FinishLoadGame(LoadBuffer*);
};
class DecalGroup { public: void SaveGame(SaveBuffer*); void LoadGame(LoadBuffer*); void FinishLoadGame(); };
class GrenadeProjectile : public Projectile { public: DecalGroup* decalGroup; bool collisionGroupReset; void Revert(LoadBuffer*); void SaveGame(SaveBuffer*); void LoadGame(LoadBuffer*); void FinishLoadGame(LoadBuffer*); void Track(); };
