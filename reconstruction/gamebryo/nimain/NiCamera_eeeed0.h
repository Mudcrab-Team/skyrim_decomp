// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCamera, NiAVObject, NiObject, NiRefObject, NiCloningProcess, AutoMemContext, CreateClone, CopyMembers, worldToCam, viewFrustum, minNearPlaneDist, maxFarNearRatio, port, lodAdjust, NiFrustum, fLeft, fRight, fTop, fBottom, fNear, fFar, bOrtho: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRect, NiPoint3, Allocate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// worldTranslate, MemoryManager, g_memoryManager, g_memoryManagerGuard, InitMemoryManager, g_memoryContext_tls_0x768, refCount: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiCloningProcess;

class MemoryManager
{
public:
    void* Allocate(std::uint32_t size, std::int32_t alignment, bool alignmentRequired);
};
extern MemoryManager g_memoryManager;
extern std::int32_t g_memoryManagerGuard;
void InitMemoryManager(MemoryManager* manager, std::int32_t* guard);

extern __declspec(thread) unsigned int g_memoryContext_tls_0x768;

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiFrustum
{
    float fLeft;
    float fRight;
    float fTop;
    float fBottom;
    float fNear;
    float fFar;
    bool bOrtho;
    std::uint8_t unk19[3];
};
static_assert(sizeof(NiFrustum) == 0x1C, "NiFrustum size");

template <class T>
struct NiRect
{
    T left;
    T right;
    T top;
    T bottom;
};
static_assert(sizeof(NiRect<float>) == 0x10, "NiRect size");

class NiRefObject
{
public:
    virtual ~NiRefObject();

    std::uint32_t refCount;  // 08
    std::uint32_t unk0C;  // 0C
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
public:
    virtual NiObject* CreateClone(NiCloningProcess& cloning);
};

class NiAVObject : public NiObject
{
public:
    void CopyMembers(NiAVObject* destination, NiCloningProcess& cloning);

    std::uint8_t unk10[0x90];  // 10
    NiPoint3 worldTranslate;  // A0
    std::uint8_t unkAC[0x64];  // AC
};
static_assert(sizeof(NiAVObject) == 0x110, "NiAVObject size");

class NiCamera : public NiAVObject
{
public:
    static void* operator new(std::size_t size)
    {
        if (g_memoryManagerGuard != 2) {
            InitMemoryManager(&g_memoryManager, &g_memoryManagerGuard);
        }
        return g_memoryManager.Allocate(static_cast<std::uint32_t>(size), 0, false);
    }

    NiCamera();
    NiObject* CreateClone(NiCloningProcess& cloning) override;
    void CopyMembers(NiCamera* destination, NiCloningProcess& cloning);

    float worldToCam[4][4];  // 110
    NiFrustum viewFrustum;  // 150
    float minNearPlaneDist;  // 16C
    float maxFarNearRatio;  // 170
    NiRect<float> port;  // 174
    float lodAdjust;  // 184
};
static_assert(sizeof(NiCamera) == 0x188, "NiCamera size");
