// Code origin: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; names, members and declarations
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSTempEffectGeometryDecal, BSTempEffectGeometryDecal::Get3D, BSTempEffectGeometryDecal::~BSTempEffectGeometryDecal, BSTempEffectGeometryDecal::GetRTTI, BSTempEffectGeometryDecal::Initialize, BSTempEffectGeometryDecal::Attach, BSTempEffectGeometryDecal::Update, BSTempEffectGeometryDecal::GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiRTTI: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiPointer, NiMatrix3, NiPoint3, BSTSmartPointer, BSGeometry, NiAVObject, NiNode, BGSTextureSet, QueuedTempEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSTempEffectGeometryDecal::decal, attachedGeometry, attachedGeometryParent, decalNode, queuedDecal, texSet, texSet2, rotation, origin, direction, width, unkA8, flags, unkB0: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiPointer::_ptr, BSTSmartPointer::_ptr, NiMatrix3::entry, NiPoint3::x, NiPoint3::y, NiPoint3::z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); member names, the pointer-only stand-ins are low-confidence guesses
#pragma once

#include <cstdint>
#include <cstddef>
#include "bsengine/BSTempEffect.h"

class NiRTTI;
class BGSTextureSet;
class QueuedTempEffect;

// Pointer-only stand-ins: this unit only converts the decal geometry pointer to NiAVObject*, so no members are declared.
class NiAVObject : public NiObject
{
};
class BSGeometry : public NiAVObject
{
};
class NiNode : public NiAVObject
{
};

template <class T>
class NiPointer
{
public:
    T* get() const { return _ptr; }
    operator T*() const { return _ptr; }

    T* _ptr;  // 00
};

template <class T>
class BSTSmartPointer
{
public:
    T* _ptr;  // 00
};

class NiPoint3
{
public:
    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

class NiMatrix3
{
public:
    float entry[3][3];  // 00
};
static_assert(sizeof(NiMatrix3) == 0x24, "NiMatrix3 size");

class BSTempEffectGeometryDecal : public BSTempEffect
{
public:
    ~BSTempEffectGeometryDecal() override;  // 00
    void* GetRTTI() const override;  // 02
    void Initialize() override;  // 25
    void Attach() override;  // 26
    bool Update(float a_arg1) override;  // 28
    NiAVObject* Get3D() const override;  // 29, compared: 0x4acd40
    TEMP_EFFECT_TYPE GetType() const override;  // 2C

    NiPointer<BSGeometry> decal;  // 30
    NiPointer<BSGeometry> attachedGeometry;  // 38
    NiPointer<NiNode> attachedGeometryParent;  // 40
    NiPointer<NiNode> decalNode;  // 48
    BSTSmartPointer<QueuedTempEffect> queuedDecal;  // 50
    BGSTextureSet* texSet;  // 58
    BGSTextureSet* texSet2;  // 60
    NiMatrix3 rotation;  // 68
    NiPoint3 origin;  // 8C
    NiPoint3 direction;  // 98
    float width;  // A4
    std::uint32_t unkA8;  // A8
    std::uint32_t flags;  // AC
    bool unkB0;  // B0
};
static_assert(sizeof(BSTempEffectGeometryDecal) == 0xB8, "BSTempEffectGeometryDecal size");
