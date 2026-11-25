// Source exposure: mixed
// Adapted bodies: none
// Code origin: handwritten minimal declarations from community headers and observed fields.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, NiInterpolator, GetSequenceInterpolator: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiLookAtInterpolator, m_aspInterpolators: SYMBOLS(fo4-pdb)
// unknown18, unknown0C: GUESS(low) STANDIN
// _refCount, ProcessClone, PostLinkObject, StreamCanSkip, GetStreamableRTTI, GetBlockAllocationSize, GetGroup, SetGroup, AsNiControllerManager: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
#include <intrin.h>

class NiObject
{
public:
    virtual ~NiObject();
    virtual void DeleteThis();
    virtual void* GetRTTI() const;
    virtual void* AsNode();
    virtual void* AsSwitchNode();
    virtual void* AsFadeNode();
    virtual void* AsMultiBoundNode();
    virtual void* AsGeometry();
    virtual void* AsTriStrips();
    virtual void* AsTriShape();
    virtual void* AsSegmentedTriShape();
    virtual void* AsSubIndexTriShape();
    virtual void* AsDynamicTriShape();
    virtual void* AsNiGeometry();
    virtual void* AsNiTriBasedGeom();
    virtual void* AsNiTriShape();
    virtual void* AsParticlesGeom();
    virtual void* AsLinesGeom();
    virtual void* AsBhkNiCollisionObject();
    virtual void* AsBhkBlendCollisionObject();
    virtual void* AsBhkAttachmentCollisionObject();
    virtual void* AsBhkRigidBody();
    virtual void* AsBhkLimitedHingeConstraint();
    virtual void* CreateClone(void*);
    virtual void LoadBinary(void*);
    virtual void LinkObject(void*);
    virtual bool RegisterStreamables(void*);
    virtual void SaveBinary(void*);
    virtual bool IsEqual(NiObject*);
    virtual void ProcessClone(void*);
    virtual void PostLinkObject(void*);
    virtual bool StreamCanSkip();
    virtual void* GetStreamableRTTI();
    virtual std::uint32_t GetBlockAllocationSize();
    virtual void* GetGroup();
    virtual void SetGroup(void*);
    virtual void* AsNiControllerManager();
    long _refCount;
    std::uint32_t unknown0C;
};


class NiInterpolator : public NiObject
{
public:
    virtual bool Update1(float, void*, void*);
    virtual bool Update2(float, void*, void*);
    virtual bool Update3(float, void*, void*);
    virtual bool Update4(float, void*, void*);
    virtual bool Update5(float, void*, void*);
    virtual bool Update6(float, void*, void*);
    virtual bool IsBoolValueSupported() const;
    virtual bool IsFloatValueSupported() const;
    virtual bool IsQuaternionValueSupported() const;
    virtual bool IsPoint3ValueSupported() const;
    virtual bool IsColorAValueSupported() const;
    virtual bool IsTransformValueSupported() const;
    virtual void Collapse();
    virtual void GetActiveTimeRange(float&, float&) const;
    virtual void GuaranteeTimeRange(float, float);
    virtual NiInterpolator* GetSequenceInterpolator(float, float);
    float lastTime;
};

class NiLookAtInterpolator : public NiInterpolator
{
public:
    NiInterpolator* GetSequenceInterpolator(float, float) override;
    std::uint8_t unknown18[56];
    NiInterpolator* m_aspInterpolators[3];
};
