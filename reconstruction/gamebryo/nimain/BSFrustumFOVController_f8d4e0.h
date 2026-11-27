// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFrustumFOVController, NiTimeController, NiInterpController, NiInterpolator, NiObject, NiRefObject, NiPointer, NiCloningProcess, AutoMemContext, CreateClone: CRASHLOGGER_PDB(59818@2026.10.24)
// NiSingleInterpController, NiFloatInterpController, Allocate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMembers, MemoryManager, g_memoryManager, g_memoryManagerGuard, InitMemoryManager, g_memoryContext_tls_0x768, refCount, activeInterpolator: GUESS(low)
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

class NiRefObject
{
public:
    virtual ~NiRefObject();

    std::uint32_t refCount;  // 08
    std::uint32_t unk0C;  // 0C
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiInterpolator : public NiRefObject
{
};

template <class T>
struct NiPointer
{
    T* object;
};

class NiObject : public NiRefObject
{
public:
    virtual NiObject* CreateClone(NiCloningProcess& cloning);
};

class NiTimeController : public NiObject
{
public:
    std::uint8_t unk10[0x38];  // 10
};
static_assert(sizeof(NiTimeController) == 0x48, "NiTimeController size");

class NiInterpController : public NiTimeController
{
};

class NiSingleInterpController : public NiInterpController
{
public:
    NiPointer<NiInterpolator> activeInterpolator;  // 48
};
static_assert(sizeof(NiSingleInterpController) == 0x50, "NiSingleInterpController size");

class NiFloatInterpController : public NiSingleInterpController
{
public:
    NiFloatInterpController();
    void CopyMembers(NiFloatInterpController* dest, NiCloningProcess& cloning);
};

class BSFrustumFOVController : public NiFloatInterpController
{
public:
    static void* operator new(std::size_t size)
    {
        if (g_memoryManagerGuard != 2) {
            InitMemoryManager(&g_memoryManager, &g_memoryManagerGuard);
        }
        return g_memoryManager.Allocate(static_cast<std::uint32_t>(size), 0, false);
    }

    BSFrustumFOVController();
    NiObject* CreateClone(NiCloningProcess& cloning) override;
};
static_assert(sizeof(BSFrustumFOVController) == 0x50, "BSFrustumFOVController size");
