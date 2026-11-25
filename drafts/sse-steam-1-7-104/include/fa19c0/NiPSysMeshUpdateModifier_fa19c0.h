// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, NiPSysModifier, IsEqual, DeleteThis, GetRTTI, AsNode, AsSwitchNode, AsFadeNode, AsMultiBoundNode, AsGeometry, AsTriStrips, AsTriShape, AsSubIndexTriShape, AsDynamicTriShape, AsNiGeometry, AsNiTriBasedGeom, AsNiTriShape, AsParticlesGeom, AsLinesGeom, AsBhkNiCollisionObject, AsBhkBlendCollisionObject, AsBhkAttachmentCollisionObject, AsBhkRigidBody, AsBhkLimitedHingeConstraint, CreateClone, LoadBinary, LinkObject, RegisterStreamables, SaveBinary, name, order, target, active, _data, _capacity, _freeIdx, _size, _growthSize: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysMeshUpdateModifier, m_kMeshes: SYMBOLS(fo4-pdb)
// MeshArray, GetAt, unknown0C, unknown1C, unknown29: GUESS(low) STANDIN

#pragma once
#include <cstdint>

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
    std::uint32_t _refCount;
    std::uint32_t unknown0C;
};

class NiPSysModifier : public NiObject
{
public:
    bool IsEqual(NiObject*) override;
    const char* name;
    std::uint32_t order;
    std::uint32_t unknown1C;
    NiObject* target;
    bool active;
    std::uint8_t unknown29[7];
};

struct MeshArray
{
    virtual ~MeshArray();
    NiObject** _data;
    std::uint16_t _capacity;
    std::uint16_t _freeIdx;
    std::uint16_t _size;
    std::uint16_t _growthSize;
    NiObject* GetAt(std::uint16_t index) const
    {
        return index < _freeIdx ? _data[index] : nullptr;
    }
};

class NiPSysMeshUpdateModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObject*) override;
    MeshArray m_kMeshes;
};
