// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiRefObject, NiObject, NiAccumulator, NiBackToFrontAccumulator, AutoMemContext, NiCamera, BSGeometry, NiCloningProcess, camera, itemsList, numItems, maxItems, items, depths, currItem, CreateClone: CRASHLOGGER_PDB(59818@2026.10.24)
// MemoryManager, Allocate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GeometryList, Node, head, tail, count, refCount, unk0C, CopyMembers, g_memoryManager, g_memoryManagerGuard, InitMemoryManager, g_memoryContext_tls_0x768: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiCamera;
class BSGeometry;
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
    unsigned int refCount;
    unsigned int unk0C;
};

class NiObject : public NiRefObject
{
public:
    virtual NiObject* CreateClone(NiCloningProcess& cloning);
};

class NiAccumulator : public NiObject
{
public:
    NiAccumulator();
    void CopyMembers(NiAccumulator* dest, NiCloningProcess& cloning);

    NiCamera* camera;
};

struct GeometryList
{
    struct Node
    {
        Node* next;
        Node* previous;
        BSGeometry* item;
    };

    GeometryList() : count(0)
    {
        head = nullptr;
        tail = nullptr;
    }

    Node* head;
    Node* tail;
    unsigned int count;
};

class NiBackToFrontAccumulator : public NiAccumulator
{
public:
    static void* operator new(std::size_t size)
    {
        if (g_memoryManagerGuard != 2) {
            InitMemoryManager(&g_memoryManager, &g_memoryManagerGuard);
        }
        return g_memoryManager.Allocate(static_cast<std::uint32_t>(size), 0, false);
    }

    NiBackToFrontAccumulator();
    NiObject* CreateClone(NiCloningProcess& cloning) override;

    GeometryList itemsList;
    int numItems;
    int maxItems;
    BSGeometry** items;
    float* depths;
    int currItem;
};
static_assert(sizeof(NiBackToFrontAccumulator) == 0x50, "NiBackToFrontAccumulator layout");
