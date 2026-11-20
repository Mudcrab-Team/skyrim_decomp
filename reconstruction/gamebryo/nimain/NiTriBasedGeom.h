/*
 * Labels: v2
 * Build: sse-steam-1-7-104; RVA 0xf1f420, 33 bytes.
 * Evidence: findings/ghidra-import.md
 * Origin: original reconstruction; member declarations adapted from CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiRefObject.h, NiObjectNET.h, NiAVObject.h, NiGeometry.h, NiTransform.h and NiBound.h.
 * Source exposure: mixed (binary-analysis and community headers).
 * Drafted by: gpt-6.1-sol
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * The constructor alone is compared. Base constructor and destructors are declarations only.
 * Class identity and complete base chain come from executable RTTI; signatures remain inferred.
 * CommonLibSSE-po3@654e55f7979c1733033d5dbef176e43827bac944 include/RE/N/NiTriBasedGeometry.h (GPL-3.0) was also consulted for the hierarchy.
 * Per-unit virtual-interface and pointer-wrapper stand-ins are incomplete; allocation and vtable contents are not claimed.
 */
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
// NiRefObject, NiObject, NiObjectNET, NiAVObject, NiGeometry: EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTriBasedGeom: EXE_RTTI
// NiRefObject, NiObject, NiObjectNET, NiAVObject, NiGeometry: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTriBasedGeom::NiTriBasedGeom, NiGeometry::NiGeometry: GUESS(low)
// Vector3, Matrix3, Transform, Bound: STANDIN GUESS(low)
// referenceCount, name, controllers, extra, extraDataSize, maxSize, parent, parentIndex, collisionObject, local, world, previousWorld, worldBound, flags, userData, fadeAmount, lastUpdatedFrameCounter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown3c, unknown108, flags02, unknown10a, propertyState, effectState, skinInstance, modelData, unknown130: GUESS(low)
#pragma once
struct Vector3 { float x, y, z; };
struct Matrix3 { float entry[3][3]; };
struct Transform { Matrix3 rotate; Vector3 translate; float scale; };
struct Bound { Vector3 center; float radius; };
class NiRefObject { public: virtual ~NiRefObject(); unsigned int referenceCount; };
class NiObject : public NiRefObject { public: virtual ~NiObject(); };
class NiObjectNET : public NiObject {
public:
    virtual ~NiObjectNET();
    const char* name;
    void* controllers;
    void** extra;
    unsigned short extraDataSize, maxSize;
};
class NiAVObject : public NiObjectNET {
public:
    virtual ~NiAVObject();
    NiAVObject* parent;
    unsigned int parentIndex, unknown3c;
    void* collisionObject;
    Transform local, world, previousWorld;
    Bound worldBound;
    unsigned int flags;
    void* userData;
    float fadeAmount;
    unsigned int lastUpdatedFrameCounter;
    unsigned char unknown108, flags02;
    unsigned short unknown10a;
};
class NiGeometry : public NiAVObject {
public:
    NiGeometry();
    virtual ~NiGeometry();
    void* propertyState;
    void* effectState;
    void* skinInstance;
    void* modelData;
    unsigned long long unknown130;
};
class NiTriBasedGeom : public NiGeometry {
public:
    NiTriBasedGeom();
    virtual ~NiTriBasedGeom();
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject public prefix");
static_assert(sizeof(NiObjectNET) == 0x30, "NiObjectNET public member layout");
static_assert(sizeof(NiAVObject) == 0x110, "NiAVObject public member layout");
static_assert(sizeof(NiGeometry) == 0x138, "NiGeometry public member layout");
