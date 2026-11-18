// Code origin: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; names, members and declarations
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSMultiBoundShape, BSMultiBoundShape::GetWithinPoint, BSMultiBoundShape::ctor, BSMultiBoundShape::~BSMultiBoundShape, BSMultiBoundShape::GetRTTI, BSMultiBoundShape::CreateClone, BSMultiBoundShape::LoadBinary, BSMultiBoundShape::LinkObject, BSMultiBoundShape::RegisterStreamables, BSMultiBoundShape::SaveBinary, BSMultiBoundShape::IsEqual, BSMultiBoundShape::GetType, BSMultiBoundShape::GetLength, BSMultiBoundShape::Unk_27, BSMultiBoundShape::Unk_28, BSMultiBoundShape::Unk_29, BSMultiBoundShape::Unk_2A, BSMultiBoundShape::Unk_2B, BSMultiBoundShape::SetCenter, BSMultiBoundShape::Unk_2E: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSMultiBoundShape::unk10, BSMultiBoundShape::pad14: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
// NiRefObject, NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiRefObject::_refCount, NiRefObject::_pad0C, NiObject::NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Local copies of the shared NiRefObject/NiObject declarations with the real NiRefObject members and a declared NiObject constructor.





class NiRefObject
{
public:
    virtual ~NiRefObject();  // 00
    virtual void DeleteThis();  // 01

    std::uint32_t _refCount;  // 08
    std::uint32_t _pad0C;  // 0C
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject community size");






class BSDynamicTriShape;
class BSFadeNode;
class BSGeometry;
class BSLines;
class BSMultiBoundNode;
class BSSegmentedTriShape;
class BSSubIndexTriShape;
class BSTriShape;
class NiCloningProcess;
class NiControllerManager;
class NiGeometry;
class NiNode;
class NiObjectGroup;
class NiParticles;
class NiRTTI;
class NiStream;
class NiSwitchNode;
class NiTriBasedGeom;
class NiTriShape;
class NiTriStrips;
class bhkAttachmentCollisionObject;
class bhkBlendCollisionObject;
class bhkLimitedHingeConstraint;
class bhkNiCollisionObject;
class bhkRigidBody;

class NiObject : public NiRefObject
{
public:
    NiObject();  // address 0xedcbc0, called by the compared constructor
    ~NiObject() override;  // 00
    virtual const NiRTTI* GetRTTI() const;  // 02
    virtual NiNode* AsNode();  // 03
    virtual NiSwitchNode* AsSwitchNode();  // 04
    virtual BSFadeNode* AsFadeNode();  // 05
    virtual BSMultiBoundNode* AsMultiBoundNode();  // 06
    virtual BSGeometry* AsGeometry();  // 07
    virtual NiTriStrips* AsTriStrips();  // 08
    virtual BSTriShape* AsTriShape();  // 09
    virtual BSSegmentedTriShape* AsSegmentedTriShape();  // 0A
    virtual BSSubIndexTriShape* AsSubIndexTriShape();  // 0B
    virtual BSDynamicTriShape* AsDynamicTriShape();  // 0C
    virtual NiGeometry* AsNiGeometry();  // 0D
    virtual NiTriBasedGeom* AsNiTriBasedGeom();  // 0E
    virtual NiTriShape* AsNiTriShape();  // 0F
    virtual NiParticles* AsParticlesGeom();  // 10
    virtual BSLines* AsLinesGeom();  // 11
    virtual bhkNiCollisionObject* AsBhkNiCollisionObject();  // 12
    virtual bhkBlendCollisionObject* AsBhkBlendCollisionObject();  // 13
    virtual bhkAttachmentCollisionObject* AsBhkAttachmentCollisionObject();  // 14
    virtual bhkRigidBody* AsBhkRigidBody();  // 15
    virtual bhkLimitedHingeConstraint* AsBhkLimitedHingeConstraint();  // 16
    virtual NiObject* CreateClone( NiCloningProcess& a_cloning);  // 17
    virtual void LoadBinary( NiStream& a_stream);  // 18
    virtual void LinkObject( NiStream& a_stream);  // 19
    virtual bool RegisterStreamables(NiStream& a_stream);  // 1A
    virtual void SaveBinary( NiStream& a_stream);  // 1B
    virtual bool IsEqual(NiObject* a_object);  // 1C
    virtual void ProcessClone(NiCloningProcess& a_cloning);  // 1D
    virtual void PostLinkObject( NiStream& a_stream);  // 1E
    virtual bool StreamCanSkip();  // 1F
    virtual const NiRTTI* GetStreamableRTTI() const;  // 20
    virtual std::uint32_t GetBlockAllocationSize() const;  // 21
    virtual NiObjectGroup* GetGroup() const;  // 22
    virtual void SetGroup( NiObjectGroup* a_group);  // 23
    virtual NiControllerManager* AsNiControllerManager();  // 24
};
static_assert(sizeof(NiObject) == 0x10, "NiObject community size");




class NiPoint3;

class BSMultiBoundShape : public NiObject
{
public:
    ~BSMultiBoundShape() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    virtual std::uint32_t GetType() = 0;  // 25
    virtual float GetLength() = 0;  // 26
    virtual bool Unk_27() = 0;  // 27
    virtual void Unk_28() = 0;  // 28
    virtual bool Unk_29() = 0;  // 29
    virtual void Unk_2A() = 0;  // 2A
    virtual void Unk_2B() = 0;  // 2B
    virtual bool GetWithinPoint(const NiPoint3& a_pos);  // compared: 0xfe4fe0  // slot 2C
    virtual void SetCenter(const NiPoint3& a_center);  // 2D
    virtual void Unk_2E();  // 2E
    BSMultiBoundShape();  // compared: 0xfe4fb0

    std::uint32_t unk10;  // 10
    std::uint32_t pad14;  // 14
};
static_assert(sizeof(BSMultiBoundShape) == 0x18, "BSMultiBoundShape size");
