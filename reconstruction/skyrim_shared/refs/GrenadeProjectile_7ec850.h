// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// GrenadeProjectile::GetCollisionGroup: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/GrenadeProjectile.cpp:147
// bhkCollisionFilter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/bhkCollisionFilter.h, include/RE/H/hkpCollisionFilter.h and its public base declarations.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class hkReferencedObject { public: virtual ~hkReferencedObject(); unsigned short memSizeAndFlags; short referenceCount; unsigned pad0c; };
class hkpCollidableCollidableFilter { public: virtual ~hkpCollidableCollidableFilter(); };
class hkpShapeCollectionFilter { public: virtual ~hkpShapeCollectionFilter(); };
class hkpRayShapeCollectionFilter { public: virtual ~hkpRayShapeCollectionFilter(); };
class hkpRayCollidableFilter { public: virtual ~hkpRayCollidableFilter(); };
class hkpCollisionFilter : public hkReferencedObject, public hkpCollidableCollidableFilter, public hkpShapeCollectionFilter, public hkpRayShapeCollectionFilter, public hkpRayCollidableFilter { public: unsigned pad30, pad34, type, pad3c, pad40, pad44; };
class bhkCollisionFilter : public hkpCollisionFilter { public: unsigned unknown48, nextSystemGroup; };
extern bhkCollisionFilter* collisionFilter;
class GrenadeProjectile { public: unsigned GetCollisionGroup() const; };
