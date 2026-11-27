// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSCullingProcess, NiCullingProcess, FlushAlphaGroupQueue, AppendNonAccum, PopFreeQueueEntry, PushQueueEntry, NiFrustum, NiFrustumPlanes, NiPlane, NiPoint3, NiCamera, NiVisibleArray, NiAVObject, BSPortalGraphEntry, BSCompoundFrustum, BSCPCullingType: CRASHLOGGER_PDB(59818@2026.10.24)
// useVirtualAppend, visibleSet, camera, frustum, planes, customCullPlanes, cameraRelatedUpdates, updateAccumulateFlag, ignorePreprocess, doCustomCullPlanes, enablePlaneOptimization, unk121, objectArray, cullQueue, roomSharedMap, portalGraphEntry, cullMode, compoundFrustum, cullModeStack, cullModeStackIndex, recurseToGeometry, isGroupingAlphas, unk301D6, alphaGroups, alphaGroupIndex, alphaGroupStopIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// IAllocatorFunctor, Allocate, Reallocate, Deallocate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AlphaGroupChunk, AlphaGroupQueue, AlphaGroupArray, AlphaGroupArrayAllocator, ArraySize, CullQueueEntry, CullQueueRing, CullQueue, RoomSharedMap, ObjectArray, MemoryManager, memoryManagerState, memoryManagerInstance, EnsureInitialized, AllocChunk, AppendIndex, vslot00: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct MemoryManager {
    void EnsureInitialized(std::uint32_t* state);
    void* Allocate(std::size_t size, std::uint32_t align, bool alignReq);
};

extern std::uint32_t memoryManagerState;
extern MemoryManager memoryManagerInstance;

struct NiPoint3 {
    float x;
    float y;
    float z;
};

struct NiPlane {
    NiPoint3 normal;
    float constant;
};

struct NiFrustum {
    float fLeft;
    float fRight;
    float fTop;
    float fBottom;
    float fNear;
    float fFar;
    bool bOrtho;
};

struct NiFrustumPlanes {
    NiPlane cullingPlanes[6];
    std::uint32_t activePlanes;
    std::uint32_t basePlaneStates;
    std::uint32_t unk68;
    std::uint32_t unk6C;
};

struct NiVisibleArray;
struct NiCamera;
struct NiAVObject;
struct BSPortalGraphEntry;
struct BSCompoundFrustum;

struct AlphaGroupChunk {
    NiAVObject* items[32];
    AlphaGroupChunk* next;
};

struct AlphaGroupQueue {
    static void* operator new(std::size_t size) throw()
    {
        if (memoryManagerState != 2u) {
            memoryManagerInstance.EnsureInitialized(&memoryManagerState);
        }
        return memoryManagerInstance.Allocate(size, 0u, false);
    }

    AlphaGroupQueue()
        : head(nullptr),
          tailNext(&head),
          tail(nullptr),
          freeChunks(nullptr),
          writeCursor(nullptr),
          readCursor(nullptr),
          count(0)
    {
    }

    AlphaGroupChunk* AllocChunk(std::size_t bytes);

    void Push(NiAVObject* const& object)
    {
        if (!tail || writeCursor == &tail->items[32]) {
            AlphaGroupChunk* chunk = freeChunks;
            if (chunk) {
                freeChunks = chunk->next;
            } else {
                chunk = AllocChunk(sizeof(AlphaGroupChunk));
            }
            chunk->next = nullptr;
            *tailNext = chunk;
            tailNext = &chunk->next;
            tail = chunk;
            writeCursor = chunk->items;
            if (!readCursor) {
                readCursor = chunk->items;
            }
        }
        NiAVObject** slot = writeCursor;
        writeCursor = slot + 1;
        ++count;
        *slot = object;
    }

    AlphaGroupChunk* head;
    AlphaGroupChunk** tailNext;
    AlphaGroupChunk* tail;
    AlphaGroupChunk* freeChunks;
    NiAVObject** writeCursor;
    NiAVObject** readCursor;
    std::uint32_t count;
};

struct AlphaGroupArray;

struct IAllocatorFunctor {
    virtual bool Allocate(std::uint32_t count, std::uint32_t elementSize) = 0;
    virtual bool Reallocate(std::uint32_t capacity, std::uint32_t front, std::uint32_t shift,
                            std::uint32_t back, std::uint32_t elementSize) = 0;
    virtual void Deallocate() = 0;
    virtual ~IAllocatorFunctor() {}
};

struct AlphaGroupArrayAllocator : IAllocatorFunctor {
    explicit AlphaGroupArrayAllocator(AlphaGroupArray& owner) : array(&owner) {}
    bool Allocate(std::uint32_t count, std::uint32_t elementSize) override;
    bool Reallocate(std::uint32_t capacity, std::uint32_t front, std::uint32_t shift,
                    std::uint32_t back, std::uint32_t elementSize) override;
    void Deallocate() override;
    ~AlphaGroupArrayAllocator() override {}

    AlphaGroupArray* array;
};

struct ArraySize {
    std::uint32_t _size;
    std::uint32_t AppendIndex(IAllocatorFunctor& allocator, std::uint32_t capacity, std::uint32_t elementSize);
};

struct AlphaGroupArray {
    AlphaGroupQueue** _data;
    std::uint32_t _capacity;
    std::uint32_t unk0C;
    ArraySize count;
    std::uint32_t unk14;

    AlphaGroupQueue* operator[](std::uint32_t index) const { return _data[index]; }

    void Append(AlphaGroupQueue* queue)
    {
        std::uint32_t index;
        {
            AlphaGroupArrayAllocator allocator(*this);
            index = count.AppendIndex(allocator, _capacity, sizeof(AlphaGroupQueue*));
        }
        _data[index] = queue;
    }
};

struct ObjectArray {
    NiAVObject** _data;
    std::uint32_t _capacity;
    std::uint32_t unk0C;
    std::uint32_t _size;
    std::uint32_t unk14;
};

struct CullQueueEntry {
    NiAVObject* object;
    int groupIndex;
    std::uint32_t flags;
};

struct CullQueueRing {
    CullQueueEntry* PopFreeQueueEntry();
    void PushQueueEntry(CullQueueEntry* entry);

    CullQueueEntry* entries[8192];
    std::uint32_t head;
    std::uint32_t tail;
    std::uint32_t commitHead;
    std::uint32_t commitTail;
};

struct CullQueue {
    CullQueueEntry pool[4096];
    CullQueueRing active;
    CullQueueRing freeList;
};

struct RoomSharedMap {
    std::uint64_t entries[6];
};

enum class BSCPCullingType : int {
    kNormal = 0,
    kAllPass = 1,
    kAllFail = 2,
    kIgnoreMultiBounds = 3,
    kForceMultiBoundsNoUpdate = 4,
};

struct NiCullingProcess {
    virtual void vslot00();
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot20();
    virtual ~NiCullingProcess();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void AppendNonAccum(NiAVObject* object, std::uint32_t flags);

    bool useVirtualAppend;
    NiVisibleArray* visibleSet;
    NiCamera* camera;
    NiFrustum frustum;
    NiFrustumPlanes planes;
    NiFrustumPlanes customCullPlanes;
    bool cameraRelatedUpdates;
    bool updateAccumulateFlag;
    bool ignorePreprocess;
    bool doCustomCullPlanes;
    bool enablePlaneOptimization;
    std::uint8_t unk121;
};

struct BSCullingProcess : NiCullingProcess {
    void FlushAlphaGroupQueue();

    ObjectArray objectArray;
    CullQueue cullQueue;
    RoomSharedMap roomSharedMap;
    BSPortalGraphEntry* portalGraphEntry;
    BSCPCullingType cullMode;
    BSCompoundFrustum* compoundFrustum;
    BSCPCullingType cullModeStack[10];
    std::uint32_t cullModeStackIndex;
    bool recurseToGeometry;
    bool isGroupingAlphas;
    std::uint8_t unk301D6;
    AlphaGroupArray alphaGroups;
    int alphaGroupIndex;
    std::uint32_t alphaGroupStopIndex;
};
