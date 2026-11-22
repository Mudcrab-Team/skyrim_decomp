// Source exposure: mixed (binary-analysis, community headers).
// Code origin: brown-room reconstruction from disassembly
// Code origin: original reconstruction from the pinned image listing; declarations from CommonLibSSE-NG (MIT). No community body copied.
// Origin: original reconstruction; types informed by CommonLibSSE-NG.
// NiNode: EXE_RTTI
// NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function4182a0, UpdateFirst, UpdateSecond, Function152a290, Function14e7f80, Functionfde7a0, UpdateFloat, QueryFlag, UpdateNode, Function6e9a50, GetPackageThatIsRunning, GetSpecialPackage, GetRunningOverride, Function639890, ConvertPosition, CountPosition: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Functionee2310: GUESS(low); the unit's task name for the compared routine
// PerformOpFunc, operator(), PerformOp, UpdateControllers, NiTObjectArray, _data, _capacity, _size, _freeIdx, _growthSize, children: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject, NiTransform, NiBound: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the shared NiAVObject.h also declares NiNode, which this unit defines, so the base is modelled here
// NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the base that places the vftable and the refcount
// NiPoint3, NiMatrix3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); transform members only
// name, controllers, extra, extraDataSize, parent, parentIndex, collisionObject, local, world, previousWorld, worldBound, flags, userData, fadeAmount, lastUpdatedFrameCounter, unk108: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// maxExtraData, unk2C, unk3C, unk10C: GUESS(low); members the compared code does not read, named after the shared header's stand-in
// _freeIdx, _growthSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG lists both after the count
// i, count, child: GUESS(low); loop index, hoisted child count and loop-local child pointer
#pragma once

#include "NiObject.h"

#include <cstdint>

class NiNode;
class NiAVObject;
class NiTimeController;
class NiExtraData;
class NiCollisionObject;
class TESObjectREFR;

// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); three floats
struct NiPoint3
{
	float x, y, z;
};

// NiMatrix3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); three rows of three floats
struct NiMatrix3
{
	float entry[3][3];
};

// NiTransform: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); sizeof 0x34 as in the image
struct NiTransform
{
	NiMatrix3 rotate;     // 00
	NiPoint3  translate;  // 24
	float     scale;      // 30
};
static_assert(sizeof(NiTransform) == 0x34, "NiTransform size");

// NiBound: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); center and radius
struct NiBound
{
	NiPoint3 center;  // 00
	float    radius;  // 0C
};
static_assert(sizeof(NiBound) == 0x10, "NiBound size");

// PerformOpFunc: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the polymorphic functor visited once per object
class PerformOpFunc
{
public:
	virtual ~PerformOpFunc();                       // 00
	virtual bool operator()(NiAVObject* a_object);  // 08
};

// NiTObjectArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); pointer array with a 16-bit count
template <class T>
class NiTObjectArray
{
public:
	virtual ~NiTObjectArray();  // 00

	T*            _data;        // 08
	std::uint16_t _capacity;    // 10
	std::uint16_t _size;        // 12
	std::uint16_t _freeIdx;     // 14
	std::uint16_t _growthSize;  // 16
};
static_assert(sizeof(NiTObjectArray<void*>) == 0x18, "NiTObjectArray size");

// NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); members up to sizeof 0x110
class NiAVObject : public NiObject
{
public:
	virtual void UpdateControllers();               // 25
	virtual void PerformOp(PerformOpFunc& a_func);  // 26

	void*              name;                    // 10
	NiTimeController*  controllers;             // 18
	NiExtraData**      extra;                   // 20
	std::uint16_t      extraDataSize;           // 28
	std::uint16_t      maxExtraData;            // 2A
	std::uint32_t      unk2C;                   // 2C
	NiNode*            parent;                  // 30
	std::uint32_t      parentIndex;             // 38
	std::uint32_t      unk3C;                   // 3C
	NiCollisionObject* collisionObject;         // 40
	NiTransform        local;                   // 48
	NiTransform        world;                   // 7C
	NiTransform        previousWorld;           // B0
	NiBound            worldBound;              // E4
	std::uint32_t      flags;                   // F4
	TESObjectREFR*     userData;                // F8
	float              fadeAmount;              // 100
	std::uint32_t      lastUpdatedFrameCounter; // 104
	std::uint32_t      unk108;                  // 108
	std::uint32_t      unk10C;                  // 10C
};
static_assert(sizeof(NiAVObject) == 0x110, "NiAVObject size");

class NiNode : public NiAVObject
{
public:
	bool Functionfde7a0();
	void QueryFlag(bool* value);
	void Functionee2310(PerformOpFunc& a_func);

	NiTObjectArray<NiAVObject*> children;  // 110
};
static_assert(sizeof(NiNode) == 0x128, "NiNode size");
