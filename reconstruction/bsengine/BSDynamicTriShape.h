// Code origin: names, bases, virtual slots and member offsets from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the two bodies are written from the listing of the pinned image
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSDynamicTriShape, BSDynamicTriShape::IsEqual, ::AsDynamicTriShape, ::GetRTTI, ::CreateClone, ::LoadBinary, ::LinkObject, ::RegisterStreamables, ::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSDynamicTriShape::dynamicData, ::lock, ::dataSize, ::frameCount, ::unk178, ::unk17C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSGeometry, BSGeometry::properties, ::skinInstance, ::rendererData, ::unk20, ::vertexDesc, ::modelBound, ::type, ::pad31, ::pad32, ::pad34 and its virtual overrides: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTriShape, BSTriShape::triangleCount, ::vertexCount, ::pad15C and its virtual overrides: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSMultiIndexTriShape, BSSkinnedDecalTriShape, NiProperty, NiSkinInstance, BSGraphics::TriShape: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declarations only
// NiBound, NiPointer, BSGraphics::VertexDesc, BSSpinLock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to their size and fields
// BSGeometry::Unk_37: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiAVObject.h"

class BSMultiIndexTriShape;
class BSSkinnedDecalTriShape;
class NiProperty;
class NiSkinInstance;

namespace BSGraphics
{
    class TriShape;

    struct VertexDesc
    {
        std::uint64_t desc;  // 00
    };
    static_assert(sizeof(VertexDesc) == 0x8, "VertexDesc size");
}

struct NiPoint3
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};

struct NiBound
{
    NiPoint3 center;  // 00
    float    radius;  // 0C
};
static_assert(sizeof(NiBound) == 0x10, "NiBound size");

template <class T>
class NiPointer
{
public:
    T* object;  // 00
};

struct BSSpinLock
{
    std::uint32_t owningThread;  // 00
    std::uint32_t lockCount;     // 04
};
static_assert(sizeof(BSSpinLock) == 0x8, "BSSpinLock size");

class BSGeometry : public NiAVObject
{
public:
    ~BSGeometry() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    BSGeometry* AsGeometry() override;  // 07
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C
    void ProcessClone(NiCloningProcess& a_cloning) override;  // 1D
    void PostLinkObject(NiStream& a_stream) override;  // 1E
    void AttachProperty(NiAlphaProperty* a_property) override;  // 27
    void SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid) override;  // 2B
    void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2C
    void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2D
    void UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2E
    void UpdateWorldBound() override;  // 2F
    void OnVisible(NiCullingProcess& a_process) override;  // 34
    virtual BSMultiIndexTriShape* AsMultiIndexTriShape();  // 35
    virtual BSSkinnedDecalTriShape* AsSkinnedDecalTriShape();  // 36
    virtual void Unk_37(void);  // 37

    NiBound                   modelBound;      // 110
    NiPointer<NiProperty>     properties[2];   // 120 - property and effect
    NiPointer<NiSkinInstance> skinInstance;    // 130
    BSGraphics::TriShape*     rendererData;    // 138
    void*                     unk20;           // 140 - smart pointer
    BSGraphics::VertexDesc    vertexDesc;      // 148
    std::uint8_t              type;            // 150
    std::uint8_t              pad31;           // 151
    std::uint16_t             pad32;           // 152
    std::uint32_t             pad34;           // 154
};
static_assert(sizeof(BSGeometry) == 0x158, "BSGeometry size");
static_assert(offsetof(BSGeometry, vertexDesc) == 0x148, "BSGeometry::vertexDesc offset");

class BSTriShape : public BSGeometry
{
public:
    ~BSTriShape() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    BSTriShape* AsTriShape() override;  // 09
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C

    std::uint16_t triangleCount;  // 158
    std::uint16_t vertexCount;    // 15A
    std::uint32_t pad15C;         // 15C
};
static_assert(sizeof(BSTriShape) == 0x160, "BSTriShape size");

class BSDynamicTriShape : public BSTriShape
{
public:
    const NiRTTI* GetRTTI() const override;  // 02
    BSDynamicTriShape* AsDynamicTriShape() override;  // 0C - compared: 0x26d490
    NiObject* CreateClone(NiCloningProcess& a_cloning) override;  // 17
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C - compared: 0xefd460

    void*         dynamicData;  // 160
    BSSpinLock    lock;         // 168
    std::uint32_t dataSize;     // 170
    std::uint32_t frameCount;   // 174
    std::uint32_t unk178;       // 178
    std::uint32_t unk17C;       // 17C
};
static_assert(sizeof(BSDynamicTriShape) == 0x180, "BSDynamicTriShape size");
static_assert(offsetof(BSDynamicTriShape, dynamicData) == 0x160, "BSDynamicTriShape::dynamicData offset");
