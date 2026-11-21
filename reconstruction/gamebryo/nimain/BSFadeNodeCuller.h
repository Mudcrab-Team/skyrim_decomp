// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction written for this project from the local function
// pack (listing only, no copied body); declarations reuse community names from the
// pinned checkouts named below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Base form: local stand-ins (no ancestor has a shared header).
// BSFadeNodeCuller, BSFadeNodeCuller::Process1, BSFadeNodeCuller::GetRTTI, BSFadeNodeCuller::~BSFadeNodeCuller, BSFadeNodeCuller::Process2, BSFadeNodeCuller::AppendVirtual: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiCullingProcess, NiNode, NiSwitchNode, BSFadeNode, BSMultiBoundNode, NiTriStrips, BSTriShape, BSSegmentedTriShape, BSSubIndexTriShape, BSDynamicTriShape, NiGeometry, NiTriBasedGeom, NiTriShape, NiParticles, BSLines, bhkNiCollisionObject, bhkBlendCollisionObject, bhkAttachmentCollisionObject, bhkRigidBody, bhkLimitedHingeConstraint: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject, NiRTTI, NiCamera, NiVisibleArray, BSGeometry: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiCullingProcess::GetRTTI, NiCullingProcess::GetAsNiNode, NiCullingProcess::GetAsNiSwitchNode, NiCullingProcess::GetAsBSFadeNode, NiCullingProcess::GetAsBSMultiBoundNode, NiCullingProcess::GetAsBSGeometry, NiCullingProcess::GetAsNiTriStrips, NiCullingProcess::GetAsBSTriShape, NiCullingProcess::GetAsBSSegmentedTriShape, NiCullingProcess::GetAsBSSubIndexTriShape, NiCullingProcess::GetAsBSDynamicTriShape, NiCullingProcess::GetAsNiGeometry, NiCullingProcess::GetAsNiTriBasedGeom, NiCullingProcess::GetAsNiTriShape, NiCullingProcess::GetAsNiParticles, NiCullingProcess::GetAsBSLines, NiCullingProcess::GetAsBhkNiCollisionObject, NiCullingProcess::GetAsBhkBlendCollisionObject, NiCullingProcess::GetAsBhkAttachmentCollisionObject, NiCullingProcess::GetAsBhkRigidBody, NiCullingProcess::GetAsBhkLimitedHingeConstraint, NiCullingProcess::~NiCullingProcess, NiCullingProcess::Process1, NiCullingProcess::Process2, NiCullingProcess::AppendVirtual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiCullingProcess::visibleSet, NiCullingProcess::camera, NiCullingProcess::frustum, NiCullingProcess::planes, NiCullingProcess::customCullPlanes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3, NiPlane, NiBound, NiFrustum, NiFrustumPlanes, NiFrustumPlanes::cullingPlanes, NiFrustumPlanes::activePlanes, NiFrustumPlanes::basePlaneStates, NiFrustumPlanes::unk68, NiFrustumPlanes::unk6C, NiFrustumPlanes::Plane::kTotal, NiTransform, NiMatrix3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject::AsFadeNode, NiAVObject::AsNode, NiAVObject::AsSwitchNode, NiAVObject::DeleteThis, NiAVObject::worldBound, NiAVObject::flags, NiAVObject::parent, NiAVObject::parentIndex, NiAVObject::collisionObject, NiAVObject::local, NiAVObject::world, NiAVObject::previousWorld, NiAVObject::userData, NiAVObject::fadeAmount, NiAVObject::lastUpdatedFrameCounter, NiAVObject::unk03C, NiAVObject::unk108, NiAVObject::flags02, NiAVObject::unk10A, NiCullingProcess::unk120, NiCullingProcess::unk121, NiAVObject::Flag::kMeshLOD, NiAVObject::Flag::kNoDismember: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject::unk00C, NiAVObject::unk02C, NiAVObject::unknown10C, NiCullingProcess::unk008, NiCullingProcess::unk00C, NiCullingProcess::unk11C, NiCullingProcess::unknown122, NiCullingProcess::unknown124: GUESS(low); meaning unknown, bytes not reachable from the compared function; typed by width to keep the pinned offsets.
#pragma once

#include <cstdint>
#include <cstddef>

class NiAVObject;
class NiRTTI;
class NiCamera;
class NiVisibleArray;
class BSGeometry;
class NiNode;
class NiSwitchNode;
class BSFadeNode;
class BSMultiBoundNode;
class NiTriStrips;
class BSTriShape;
class BSSegmentedTriShape;
class BSSubIndexTriShape;
class BSDynamicTriShape;
class NiGeometry;
class NiTriBasedGeom;
class NiTriShape;
class NiParticles;
class BSLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkAttachmentCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;

struct NiPoint3
{
	float x;  // 00
	float y;  // 04
	float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

// NiMatrix3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiMatrix3
{
	NiPoint3 entry[3];  // 00
};
static_assert(sizeof(NiMatrix3) == 0x24, "NiMatrix3 size");

// NiTransform: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiTransform
{
	NiMatrix3 rotate;     // 00
	NiPoint3  translate;  // 24
	float     scale;      // 30
};
static_assert(sizeof(NiTransform) == 0x34, "NiTransform size");

// NiPlane: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiPlane
{
	NiPoint3 normal;    // 00
	float    constant;  // 0C
};
static_assert(sizeof(NiPlane) == 0x10, "NiPlane size");

// NiBound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiBound
{
	NiPoint3 center;  // 00
	float    radius;  // 0C
};
static_assert(sizeof(NiBound) == 0x10, "NiBound size");

// NiFrustum: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiFrustum
{
	float fLeft;    // 00
	float fRight;   // 04
	float fTop;     // 08
	float fBottom;  // 0C
	float fNear;    // 10
	float fFar;     // 14
	bool  bOrtho;   // 18
};
static_assert(sizeof(NiFrustum) == 0x1C, "NiFrustum size");

// NiFrustumPlanes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiFrustumPlanes
{
	enum Plane
	{
		kNear,
		kFar,
		kLeft,
		kRight,
		kTop,
		kBottom,

		kTotal
	};

	NiPlane       cullingPlanes[kTotal];  // 00
	std::uint32_t activePlanes;           // 60
	std::uint32_t basePlaneStates;        // 64
	std::uint32_t unk68;                  // 68
	std::uint32_t unk6C;                  // 6C
};
static_assert(sizeof(NiFrustumPlanes) == 0x70, "NiFrustumPlanes size");

// NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiAVObject
{
public:
	enum class Flag : std::uint32_t
	{
		kMeshLOD = 1u << 12,      // 0x00001000
		kNoDismember = 1u << 20,  // 0x00100000
	};

	virtual ~NiAVObject();                 // 00
	virtual void          DeleteThis();    // 01
	virtual const NiRTTI* GetRTTI() const;  // 02
	virtual NiNode*       AsNode();        // 03
	virtual NiSwitchNode* AsSwitchNode();  // 04
	virtual BSFadeNode*   AsFadeNode();    // 05

	// members
	std::uint32_t refCount;                  // 008
	std::uint32_t unk00C;                    // 00C
	void*         name;                      // 010
	void*         controllers;               // 018
	void*         extra;                     // 020
	std::uint32_t extraDataSize;             // 028
	std::uint32_t unk02C;                    // 02C
	NiNode*       parent;                    // 030
	std::uint32_t parentIndex;               // 038
	std::uint32_t unk03C;                    // 03C
	void*         collisionObject;           // 040
	NiTransform   local;                     // 048
	NiTransform   world;                     // 07C
	NiTransform   previousWorld;             // 0B0
	NiBound       worldBound;                // 0E4
	std::uint32_t flags;                     // 0F4
	void*         userData;                  // 0F8
	float         fadeAmount;                // 100
	std::uint32_t lastUpdatedFrameCounter;   // 104
	std::uint8_t  unk108;                    // 108
	std::uint8_t  flags02;                   // 109
	std::uint16_t unk10A;                    // 10A
	std::uint32_t unknown10C;                // 10C
};
static_assert(sizeof(NiAVObject) == 0x110, "NiAVObject size");

// BSFadeNode: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the inherited NiAVObject layout is read by this unit.
class BSFadeNode : public NiAVObject
{
};

class NiCullingProcess
{
public:
	virtual const NiRTTI* GetRTTI() const;  // 00
	virtual NiNode* GetAsNiNode();  // 01
	virtual NiSwitchNode* GetAsNiSwitchNode();  // 02
	virtual BSFadeNode* GetAsBSFadeNode();  // 03
	virtual BSMultiBoundNode* GetAsBSMultiBoundNode();  // 04
	virtual BSGeometry* GetAsBSGeometry();  // 05
	virtual NiTriStrips* GetAsNiTriStrips();  // 06
	virtual BSTriShape* GetAsBSTriShape();  // 07
	virtual BSSegmentedTriShape* GetAsBSSegmentedTriShape();  // 08
	virtual BSSubIndexTriShape* GetAsBSSubIndexTriShape();  // 09
	virtual BSDynamicTriShape* GetAsBSDynamicTriShape();  // 0A
	virtual NiGeometry* GetAsNiGeometry();  // 0B
	virtual NiTriBasedGeom* GetAsNiTriBasedGeom();  // 0C
	virtual NiTriShape* GetAsNiTriShape();  // 0D
	virtual NiParticles* GetAsNiParticles();  // 0E
	virtual BSLines* GetAsBSLines();  // 0F
	virtual bhkNiCollisionObject* GetAsBhkNiCollisionObject();  // 10
	virtual bhkBlendCollisionObject* GetAsBhkBlendCollisionObject();  // 11
	virtual bhkAttachmentCollisionObject* GetAsBhkAttachmentCollisionObject();  // 12
	virtual bhkRigidBody* GetAsBhkRigidBody();  // 13
	virtual bhkLimitedHingeConstraint* GetAsBhkLimitedHingeConstraint();  // 14
	virtual ~NiCullingProcess();  // 15
	virtual void Process1(NiAVObject* a_object, std::uint32_t a_arg2);  // 16
	virtual void Process2(const NiCamera* a_camera, NiAVObject* a_scene, NiVisibleArray* a_visibleSet);  // 17
	virtual void AppendVirtual(BSGeometry& a_visible, std::uint32_t a_arg2);  // 18

	// members
	std::uint32_t   unk008;            // 008
	std::uint32_t   unk00C;            // 00C
	NiVisibleArray* visibleSet;        // 010
	const NiCamera* camera;            // 018
	NiFrustum       frustum;           // 020
	NiFrustumPlanes planes;            // 03C
	NiFrustumPlanes customCullPlanes;  // 0AC
	std::uint32_t   unk11C;            // 11C
	std::uint8_t    unk120;            // 120
	std::uint8_t    unk121;            // 121
	std::uint16_t   unknown122;        // 122
	std::uint32_t   unknown124;        // 124
};
static_assert(sizeof(NiCullingProcess) == 0x128, "NiCullingProcess size");

class BSFadeNodeCuller : public NiCullingProcess
{
public:
	const NiRTTI* GetRTTI() const override;  // 00
	~BSFadeNodeCuller() override;  // 15
	virtual void Process1(NiAVObject* a_object, std::int32_t a_arg2);  // compared: 0x1555fd0  // slot 16
	void Process2(const NiCamera* a_camera, NiAVObject* a_scene, NiVisibleArray* a_visibleSet) override;  // 17
	virtual void AppendVirtual(BSGeometry& a_visible, std::int32_t a_arg2);  // 18
};
static_assert(sizeof(BSFadeNodeCuller) == 0x128, "BSFadeNodeCuller size");
