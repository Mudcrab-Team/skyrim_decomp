// Code origin: names, bases, virtual slots and member offsets from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the body is written from the listing of the pinned image
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiSkinData, NiSkinData::RegisterStreamables, ::~NiSkinData, ::GetRTTI, ::LoadBinary, ::LinkObject, ::SaveBinary, ::IsEqual, ::skinPartition, ::rootParentToSkin, ::boneData, ::bones, ::pad5C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiSkinPartition, NiPointer, NiTransform, NiPoint3, NiSkinData::BoneData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to the layout the class needs (BoneData is only a pointer target)
// NiTransform::rotate, ::translate, ::scale: GUESS(low); NG's NiMatrix3 is stored as nine floats
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiObject.h"

class NiSkinPartition;

template <class T>
class NiPointer
{
public:
    T* object;  // 00
};

struct NiPoint3
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};

struct NiTransform
{
    float    rotate[3][3];  // 00
    NiPoint3 translate;     // 24
    float    scale;         // 30
};
static_assert(sizeof(NiTransform) == 0x34, "NiTransform size");

class NiSkinData : public NiObject
{
public:
    struct BoneData;

    ~NiSkinData() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    void LoadBinary(NiStream& a_stream) override;  // 18
    void LinkObject(NiStream& a_stream) override;  // 19
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A - compared: 0xf0db60
    void SaveBinary(NiStream& a_stream) override;  // 1B
    bool IsEqual(NiObject* a_object) override;  // 1C

    NiPointer<NiSkinPartition> skinPartition;     // 10
    NiTransform                rootParentToSkin;  // 18
    BoneData*                  boneData;          // 50
    std::uint32_t              bones;             // 58
    std::uint32_t              pad5C;             // 5C
};
static_assert(sizeof(NiSkinData) == 0x60, "NiSkinData size");
static_assert(offsetof(NiSkinData, boneData) == 0x50, "NiSkinData::boneData offset");
