// Code origin: Local analysis and CommonLibSSE-NG type declarations. The stream write helpers are adapted from CharmedBaryon/CommonLibSSE-NG at b93280e, include/RE/N/NiBinaryStream.h and src/RE/N/NiBinaryStream.cpp (MIT).
// Source exposure: mixed (community declarations and the contributor-owned pack; bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiSkinInstance, NiSkinInstance::~NiSkinInstance, NiSkinInstance::LoadBinary, NiSkinInstance::RegisterStreamables, NiSkinInstance::SaveBinary, NiSkinInstance::IsEqual, NiSkinInstance::Unk_25, NiSkinInstance::GetRTTI, NiSkinInstance::CreateClone, NiSkinInstance::LinkObject, NiSkinInstance::PostLinkObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiSkinData, NiBinaryStream, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBinaryStream::write, NiBinaryStream::binary_write, NiStream::SaveLinkID, oStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// skinData, skinPartition, rootParent, bones, boneWorldTransforms, frameID, numMatrices, numRegisters, allocatedSize, boneMatrices, prevBoneMatrices, skinToWorldWorldToSkinMatrix, lock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SkinInstanceLock: STANDIN GUESS(low); stands for the community lock type REX::W32::CRITICAL_SECTION, initialized by the platform API
// DebugInfo, LockCount, RecursionCount, OwningThread, LockSemaphore, SpinCount: STANDIN GUESS(low); the documented Windows critical-section member names and sizes
// NiPoint3, NiMatrix3, NiTransform, BSStreamHeader, skinPartition, rootParentToSkin, boneData, bones, pad5C, header, nifMaxVersion, nifMaxUserDefinedVersion, inputFilePath, unk20C, unk20E, unk210, iStr, oStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names, offsets and sizes as declared there, pointer types are guesses
// unk0D0, unk0D8, unk0E0, unk0E8, unk0F0, unk0F8, unk218, unk220, unk228, unk230, unk238, unk240, unk248, unk250, unk258, unk260, unk268, unk270, unk278, unk280, unk288, unk290: GUESS(low); NiStream storage the community types as containers, kept as plain words
// Value, unk10, unk0C, outputCursor, writeCallback, elementByteCount, elementsToWrite, payloadBytes, widths, emittedBytes, length, widthCount, total, streamRef, comparedObject, cloneContext, linkTarget: GUESS(low)
// LoadLinkID, SkipLinkIDs: GUESS(low); stream operations identified by their use in the load path
// unk01 through unk0B: GUESS(low); virtual slots outside this unit
// NiSkinInstance::Ctor: OBSERVED; placement construction entry
#pragma once

#include <cstdint>
#include "NiObject.h"

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

class NiTransform
{
public:
    NiMatrix3 rotate;     // 00
    NiPoint3  translate;  // 24
    float     scale;      // 30
};
static_assert(sizeof(NiTransform) == 0x34, "NiTransform size");

class NiSkinPartition;
class NiSkinData : public NiObject
{
public:
    NiSkinPartition* skinPartition;  // 10
    NiTransform rootParentToSkin;    // 18
    void* boneData;                  // 50
    std::uint32_t bones;             // 58
    std::uint32_t pad5C;             // 5C
};
static_assert(sizeof(NiSkinData) == 0x60, "NiSkinData size");

class NiBinaryStream
{
public:
    virtual ~NiBinaryStream();

    std::uint32_t binary_write(const void* payloadBytes, std::uint32_t length,
                               std::uint32_t* widths, std::uint32_t widthCount = 1)
    {
        const std::uint32_t emittedBytes = writeCallback(this, payloadBytes, length, widths, widthCount);
        outputCursor += emittedBytes;
        return emittedBytes;
    }

    template <class Value>
    bool write(const Value* elementsToWrite, std::uint32_t widthCount)
    {
        std::uint32_t elementByteCount = sizeof(Value);
        std::uint32_t total = widthCount * elementByteCount;
        return binary_write(elementsToWrite, total, &elementByteCount) == total;
    }

    std::uint32_t outputCursor;
    std::uint32_t unk0C;
    void* unk10;
    std::uint32_t (*writeCallback)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};

struct BSStreamHeader
{
    std::uint32_t version;            // 00
    char author[64];                  // 04
    char processScript[64];           // 44
    char exportScript[64];            // 84
    std::uint32_t padC4;              // C4
};
static_assert(sizeof(BSStreamHeader) == 0xC8, "BSStreamHeader size");

class NiStream
{
public:
    virtual ~NiStream();
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
    virtual void SaveLinkID(const NiObject* linkTarget);

    void LoadLinkID();
    void SkipLinkIDs();

    BSStreamHeader header;  // 008
    std::uint64_t unk0D0;  // 0D0
    std::uint64_t unk0D8;  // 0D8
    std::uint64_t unk0E0;  // 0E0
    std::uint64_t unk0E8;  // 0E8
    std::uint64_t unk0F0;  // 0F0
    std::uint64_t unk0F8;  // 0F8
    std::uint32_t nifMaxVersion;             // 100
    std::uint32_t nifMaxUserDefinedVersion;  // 104
    char inputFilePath[260];                 // 108
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
    NiBinaryStream* oStr;
};

struct SkinInstanceLock
{
    SkinInstanceLock() noexcept;
    void* DebugInfo;            // 00
    std::int32_t LockCount;     // 08
    std::int32_t RecursionCount;  // 0C
    void* OwningThread;         // 10
    void* LockSemaphore;        // 18
    std::uint64_t SpinCount;    // 20
};
static_assert(sizeof(SkinInstanceLock) == 0x28, "SkinInstanceLock size");

// NiPointer, get: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// pointee: GUESS(low)
template <class Value>
class NiPointer
{
public:
    NiPointer() noexcept : pointee(nullptr) {}
    ~NiPointer() noexcept;

    Value* get() const noexcept
    {
        return pointee;
    }

private:
    Value* pointee;
};

class NiSkinInstance : public NiObject
{
public:
    NiSkinInstance();
    ~NiSkinInstance() override;
    const NiRTTI* GetRTTI() const override;
    NiObject* CreateClone(NiCloningProcess& cloneContext) override;
    void LoadBinary(NiStream& streamRef) override;
    void LinkObject(NiStream& streamRef) override;
    bool RegisterStreamables(NiStream& streamRef) override;
    void SaveBinary(NiStream& streamRef) override;
    bool IsEqual(NiObject* comparedObject) override;
    void PostLinkObject(NiStream& streamRef) override;
    virtual void Unk_25();
    NiSkinInstance* Ctor();

    NiPointer<NiSkinData> skinData;
    NiPointer<NiObject> skinPartition;
    NiObject* rootParent;
    NiObject** bones;
    const void** boneWorldTransforms;
    std::uint32_t frameID{ UINT32_MAX };
    std::uint32_t numMatrices;
    std::uint32_t numRegisters;
    std::uint32_t allocatedSize;
    void* boneMatrices;
    void* prevBoneMatrices;
    void* skinToWorldWorldToSkinMatrix;
    SkinInstanceLock lock;
};
static_assert(sizeof(NiSkinInstance) == 0x88, "NiSkinInstance size");
