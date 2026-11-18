// Type declarations for the BSInstanceTriShape translation unit (build sse-steam-1-7-104).
//
// Labels: v2
// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CharmedBaryon/CommonLibSSE-NG (MIT); the member offsets, types and sizes follow that declaration; no external implementation body is copied.
// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// Community names are unverified. Only the members the compared code needs are declared.
// BSInstanceTriShape, BSInstanceTriShape::BSInstanceTriShape, BSInstanceTriShape::~BSInstanceTriShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSTriShape, BSTriShape::~BSTriShape, BSFixedString, NiPoint3, NiMatrix3, NiBound, NiTransform: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names and sizes as declared there, stand-ins limited to the members below
// _refCount, _pad0C, name, controllers, extra, extraDataSize, maxSize, pad2C, parent, parentIndex, unk03C, collisionObject, local, world, previousWorld, worldBound, flags, userData, fadeAmount, lastUpdatedFrameCounter, unk108, flags02, unk10A, pad10C, modelBound, properties, skinInstance, rendererData, unk20, vertexDesc, type, pad31, pad32, pad34, triangleCount, vertexCount, pad15C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names, offsets and sizes as declared there (NiRefObject, NiObjectNET, NiAVObject and BSGeometry members are flattened into BSTriShape)
// The community smart-pointer members, the enumeration members and BSGraphics::VertexDesc: GUESS(low); declared as raw pointers, plain integers and std::uint64_t
// The MIT notice below covers only the names and declarations taken from
// CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; the other code in this file
// is covered by the repository licence and the provenance labels above.
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#pragma once

#include <cstdint>

class NiTimeController;
class NiExtraData;
class NiNode;
class NiCollisionObject;
class TESObjectREFR;
class NiProperty;
class NiSkinInstance;

class BSFixedString {
public:
    const char* _data;  // 0
};

class NiPoint3 {
public:
    float x;  // 0
    float y;  // 4
    float z;  // 8
};

class NiMatrix3 {
public:
    float entry[3][3];  // 00
};

class NiBound {
public:
    NiPoint3 center;  // 00
    float radius;     // 0C
};
static_assert(sizeof(NiBound) == 0x10, "NiBound size");

class NiTransform {
public:
    NiMatrix3 rotate;     // 00
    NiPoint3 translate;   // 24
    float scale;          // 30
};
static_assert(sizeof(NiTransform) == 0x34, "NiTransform size");

class BSTriShape {
public:
    virtual ~BSTriShape();

    std::uint32_t _refCount;  // 08
    std::uint32_t _pad0C;     // 0C
    BSFixedString name;  // 10
    NiTimeController* controllers;  // 18
    NiExtraData** extra;  // 20
    std::uint16_t extraDataSize;  // 28
    std::uint16_t maxSize;  // 2A
    std::uint32_t pad2C;  // 2C
    NiNode* parent;  // 30
    std::uint32_t parentIndex;  // 38
    std::uint32_t unk03C;  // 3C
    NiCollisionObject* collisionObject;  // 40
    NiTransform local;  // 48
    NiTransform world;  // 7C
    NiTransform previousWorld;  // B0
    NiBound worldBound;  // E4
    std::uint32_t flags;  // F4
    TESObjectREFR* userData;  // F8
    float fadeAmount;  // 100
    std::uint32_t lastUpdatedFrameCounter;  // 104
    std::uint8_t unk108;  // 108
    std::uint8_t flags02;  // 109
    std::uint16_t unk10A;  // 10A
    std::uint32_t pad10C;  // 10C
    NiBound modelBound;  // 110
    NiProperty* properties[2];  // 120
    NiSkinInstance* skinInstance;  // 130
    void* rendererData;  // 138
    void* unk20;  // 140
    std::uint64_t vertexDesc;  // 148
    std::uint8_t type;  // 150
    std::uint8_t pad31;  // 151
    std::uint16_t pad32;  // 152
    std::uint32_t pad34;  // 154
    std::uint16_t triangleCount;  // 158
    std::uint16_t vertexCount;  // 15A
    std::uint32_t pad15C;  // 15C
};
static_assert(sizeof(BSTriShape) == 0x160, "BSTriShape size");

class BSInstanceTriShape : public BSTriShape {
public:
    BSInstanceTriShape();
    virtual ~BSInstanceTriShape();  // compared: 0xfe4240 (scalar deleting destructor)
};
static_assert(sizeof(BSInstanceTriShape) == 0x160, "BSInstanceTriShape size");
