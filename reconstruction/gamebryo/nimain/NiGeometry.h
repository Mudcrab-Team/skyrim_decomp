// Code origin: Community declarations and local analysis. Stand-ins describe only the observed fields and calls.
// Source exposure: mixed (community names and pinned-image analysis).
// Adapted bodies: NiBinaryStream::write and NiBinaryStream::binary_write, from CharmedBaryon/CommonLibSSE-NG at b93280e (MIT), include/RE/N/NiBinaryStream.h and src/RE/N/NiBinaryStream.cpp; the writer is inlined in this view and assumes a configured output callback.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiGeometry, NiUpdateData, NiBinaryStream, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiGeometry::RegisterStreamables, NiGeometry::SaveBinary, NiGeometry::PostLinkObject, NiGeometry::SetSelectiveUpdateFlags, NiGeometry::UpdateDownwardPass, NiGeometry::UpdateSelectedDownwardPass, NiGeometry::Unk_36, NiGeometry::Unk_37, NiGeometry::Unk_3A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GeometryStreamView, GeometryControllerView, GeometryRefView, GeometryCollisionView, GeometryPropertyView: STANDIN GUESS(low)
// m_spPropertyState, m_spEffectState, m_spModelData, m_spSkinInstance, unk130: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// flags, time: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBinaryStream::write, NiBinaryStream::binary_write: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Value, elementsToWrite, count, elementByteCount, total, payloadBytes, sizes, written: GUESS(low)
// unk01 through unk19, unk1B through unk29: GUESS(low); slots unused by this unit
// unk00, unk0C, unk10, refCount, WriteBytes, bytesWritten, output, RefreshSkin, ClearState, UpdateState: GUESS(low)
// Destroy, RegisterObjectStreamables, HasVertexEffect, nextController, propertyControllers, WriteObjectLink: GUESS(low)
// streamRef, updateData, a_mode, a_update, a_transforms, rigidResult, a_skin, a_object: GUESS(low)
// member10, member18, member20, member28, member30, member38: GUESS(low); storage between the reference count and nextController, not read by the compared code
// member10: GUESS(low); storage after the reference count, not read by the compared code
// BSFixedString, NiPoint3, NiMatrix3, NiBound, NiTransform, BSStreamHeader, version, author, processScript, exportScript, padC4: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names, offsets and sizes as declared there
// header, nifMaxVersion, nifMaxUserDefinedVersion, inputFilePath, unk20C, unk20E, unk210, iStr: STANDIN GUESS(low); the NiStream member names and offsets of the community declaration, used on this stand-in view
// unkD0, unkD8, unkE0, unkE8, unkF0, unkF8, unk210, unk218, unk220, unk228, unk230, unk238, unk240, unk248, unk250, unk258, unk260, unk268, unk270, unk278, unk280, unk288, unk290: GUESS(low); stream storage the community types as containers, kept as plain words
// name, controllers, extra, extraDataSize, maxSize, pad2C, parent, parentIndex, collisionObject, local, world, previousWorld, worldBound, flags, userData, fadeAmount, lastUpdatedFrameCounter, flags02, unk10A, pad10C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names, offsets and sizes as declared there (NiObjectNET and NiAVObject members flattened into this class), the pointer types are guesses
// unk03C, unk108: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names and offsets as declared there
// unk00: GUESS(low); the vtable pointer slot of the community base
#pragma once

#include <cstdint>
#include <cstddef>
class NiStream;

class NiTimeController;
class NiExtraData;
class NiNode;
class NiCollisionObject;
class TESObjectREFR;

class BSFixedString
{
public:
    const char* _data;  // 0
};

class NiPoint3
{
public:
    float x;  // 0
    float y;  // 4
    float z;  // 8
};

class NiMatrix3
{
public:
    float entry[3][3];  // 00
};

class NiBound
{
public:
    NiPoint3 center;  // 00
    float radius;  // 0C
};
static_assert(sizeof(NiBound) == 0x10, "NiBound size");

class NiTransform
{
public:
    NiMatrix3 rotate;  // 00
    NiPoint3 translate;  // 24
    float scale;  // 30
};
static_assert(sizeof(NiTransform) == 0x34, "NiTransform size");

class NiUpdateData
{
public:
    float time;
    std::uint32_t flags;
};
static_assert(sizeof(NiUpdateData) == 8, "NiUpdateData represented size");

class GeometryRefView
{
public:
    virtual ~GeometryRefView();
    virtual void Destroy();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual bool RegisterObjectStreamables(NiStream& streamRef);

    long refCount;
};

// GeometryObjectView: STANDIN GUESS(low); common slots before controller and collision dispatch
class GeometryObjectView : public GeometryRefView
{
public:
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
};

// Next pointer placement and the predicate slot are observed independently on this build.
class GeometryControllerView : public GeometryObjectView
{
public:
    virtual void unk25();
    virtual void unk26();
    virtual void unk27();
    virtual void unk28();
    virtual void unk29();
    virtual bool HasVertexEffect() const;

    std::uint64_t member10;  // 10
    std::uint64_t member18;  // 18
    std::uint64_t member20;  // 20
    std::uint64_t member28;  // 28
    std::uint64_t member30;  // 30
    std::uint64_t member38;  // 38
    GeometryControllerView* nextController;
};

class GeometryCollisionView : public GeometryObjectView
{
public:
    virtual void unk25();
    virtual void UpdateState(NiUpdateData& updateData);
    virtual void ClearState();
};

struct GeometryPropertyView : GeometryRefView
{
    std::uint64_t member10;  // 10
    void* propertyControllers;
};

class NiBinaryStream
{
public:
    std::uint32_t binary_write(const void* payloadBytes, std::uint32_t total,
                               std::uint32_t* sizes, std::uint32_t count = 1)
    {
        const std::uint32_t written = WriteBytes(this, payloadBytes, total, sizes, count);
        bytesWritten += written;
        return written;
    }

    template <class Value>
    bool write(const Value* elementsToWrite, std::uint32_t count)
    {
        std::uint32_t elementByteCount = sizeof(Value);
        std::uint32_t total = count * elementByteCount;
        return binary_write(elementsToWrite, total, &elementByteCount) == total;
    }

    virtual ~NiBinaryStream();
    virtual void unk01();
    virtual void unk02();

    // This callback is stored in the stream object rather than called through its vtable.
    std::uint32_t bytesWritten;
    std::uint32_t unk0C;
    void* unk10;
    std::uint32_t (*WriteBytes)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};
static_assert(sizeof(NiBinaryStream) == 0x20, "NiBinaryStream represented size");

struct BSStreamHeader
{
    std::uint32_t version;  // 00
    char author[64];  // 04
    char processScript[64];  // 44
    char exportScript[64];  // 84
    std::uint32_t padC4;  // C4
};
static_assert(sizeof(BSStreamHeader) == 0xC8, "BSStreamHeader size");

class GeometryStreamView
{
public:
    virtual ~GeometryStreamView();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void WriteObjectLink(const GeometryRefView* a_object);

    BSStreamHeader header;  // 008
    std::uint64_t unkD0;  // D0
    std::uint64_t unkD8;  // D8
    std::uint64_t unkE0;  // E0
    std::uint64_t unkE8;  // E8
    std::uint64_t unkF0;  // F0
    std::uint64_t unkF8;  // F8
    std::uint32_t nifMaxVersion;  // 100
    std::uint32_t nifMaxUserDefinedVersion;  // 104
    char inputFilePath[260];  // 108
    std::uint16_t unk20C;  // 20C
    std::uint16_t unk20E;  // 20E
    std::uint64_t unk210;  // 210
    std::uint64_t unk218;  // 218
    std::uint64_t unk220;  // 220
    std::uint64_t unk228;  // 228
    std::uint64_t unk230;  // 230
    std::uint64_t unk238;  // 238
    std::uint64_t unk240;  // 240
    std::uint64_t unk248;  // 248
    std::uint64_t unk250;  // 250
    std::uint64_t unk258;  // 258
    std::uint64_t unk260;  // 260
    std::uint64_t unk268;  // 268
    std::uint64_t unk270;  // 270
    std::uint64_t unk278;  // 278
    std::uint64_t unk280;  // 280
    std::uint64_t unk288;  // 288
    std::uint64_t unk290;  // 290
    NiBinaryStream* iStr;  // 298
    NiBinaryStream* output;
};

class NiGeometry
{
public:
    bool RegisterStreamables(NiStream& streamRef);
    void SaveBinary(NiStream& streamRef);
    void UpdateDownwardPass(NiUpdateData& updateData, std::uint32_t a_mode);
    void UpdateSelectedDownwardPass(NiUpdateData& updateData, std::uint32_t a_mode);
    // The original return type is unknown. This stand-in represents the observed register result.
    std::uint32_t Unk_36();
    void Unk_37(GeometryRefView* a_skin);
    void* Unk_3A();
    void PostLinkObject(NiStream& streamRef);
    void SetSelectiveUpdateFlags(bool& a_update, bool a_transforms, bool& rigidResult);

    void RefreshSkin(NiUpdateData& updateData);

    std::uint64_t unk00;  // 00
    std::uint32_t _refCount;  // 08
    std::uint32_t _pad0C;  // 0C
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
    GeometryPropertyView* m_spPropertyState;
    GeometryPropertyView* m_spEffectState;
    GeometryRefView* m_spSkinInstance;
    GeometryRefView* m_spModelData;
    std::uint64_t unk130;
};
static_assert(sizeof(NiGeometry) == 0x138, "NiGeometry represented size");
