// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSCullingProcess, NiCullingProcess, NiFrustum, NiFrustumPlanes, NiPlane, NiPoint3, NiCamera, NiVisibleArray, NiAVObject, BSPortalGraphEntry, BSCompoundFrustum, BSCPCullingType: CRASHLOGGER_PDB(59818@2026.10.24)
// useVirtualAppend, visibleSet, camera, frustum, planes, customCullPlanes, cameraRelatedUpdates, updateAccumulateFlag, ignorePreprocess, doCustomCullPlanes, enablePlaneOptimization, unk121, objectArray, cullQueue, roomSharedMap, portalGraphEntry, cullMode, compoundFrustum, cullModeStack, cullModeStackIndex, recurseToGeometry, isGroupingAlphas, unk301D6, alphaGroups, alphaGroupIndex, alphaGroupStopIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// ArrayHeapAllocator, ArrayBase, ObjectArray, AlphaGroupArray, CullQueueEntry, CullQueueRing, CullQueue, RoomSharedTable, RoomSharedMap, roomSharedSentinel: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <cstring>
#include <intrin.h>

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);

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

struct NiCullingProcess {
    explicit NiCullingProcess(NiVisibleArray* visibleSet);
    virtual ~NiCullingProcess();

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

enum class BSCPCullingType : int {
    kNormal = 0,
    kAllPass = 1,
    kAllFail = 2,
    kIgnoreMultiBounds = 3,
    kForceMultiBoundsNoUpdate = 4,
};

struct ArrayHeapAllocator {
    ArrayHeapAllocator();
    ~ArrayHeapAllocator();

    void* _data;
    std::uint32_t _capacity;
};

struct ArrayBase {
    ArrayBase();

    std::uint32_t _size;
};

struct ObjectArray : ArrayHeapAllocator, ArrayBase {
    ObjectArray() {}
    ~ObjectArray();
};

struct AlphaGroupArray : ArrayHeapAllocator, ArrayBase {
    AlphaGroupArray() {}
};

struct CullQueueEntry {
    NiAVObject* object;
    int groupIndex;
    std::uint32_t flags;
};

struct CullQueueRing {
    CullQueueEntry* entries[8192];
    // volatile: lockless ring indices accessed via interlocked compare-exchange
    volatile long head;
    // volatile: lockless ring indices accessed via interlocked compare-exchange
    volatile long tail;
    // volatile: lockless ring indices accessed via interlocked compare-exchange
    volatile long commitHead;
    // volatile: lockless ring indices accessed via interlocked compare-exchange
    volatile long commitTail;

    void Init()
    {
        std::memset(entries, 0, sizeof(entries));
        head = 0;
        commitHead = 0;
        tail = 0;
        commitTail = 0;
    }

    void Push(CullQueueEntry* entry)
    {
        for (;;) {
            long currentTail = commitTail;
            long nextTail = currentTail + 1;
            if (((tail ^ nextTail) & 0x1FFF) == 0) {
                Sleep(0);
                continue;
            }
            // Atomically claim the next ring slot for lockless queue insertion.
            if (_InterlockedCompareExchange(&commitTail, nextTail, currentTail) == currentTail) {
                entries[currentTail & 0x1FFF] = entry;
                long cur = commitHead;
                while (entries[cur & 0x1FFF] != nullptr) {
                    long tailSnapshot = commitTail;
                    if (commitHead == tailSnapshot) {
                        break;
                    }
                    // Advance published producer index across consecutive filled ring slots.
                    if (_InterlockedCompareExchange(&commitHead, cur + 1, cur) != cur) {
                        break;
                    }
                    cur = commitHead;
                }
                return;
            }
        }
    }
};

struct CullQueue {
    CullQueueEntry pool[4096];
    CullQueueRing active;
    CullQueueRing freeList;

    CullQueue()
    {
        active.Init();
        freeList.Init();
        for (int i = 0; i < 4096; ++i) {
            freeList.Push(&pool[i]);
        }
    }
};

extern std::uint8_t roomSharedSentinel[];

struct RoomSharedTable {
    RoomSharedTable()
        : size(0), freeCount(0), lastFree(0), sentinel(roomSharedSentinel), entries(nullptr)
    {
    }
    ~RoomSharedTable();

    std::uint32_t unk00;
    std::uint32_t size;
    std::uint32_t freeCount;
    std::uint32_t lastFree;
    void* sentinel;
    std::uint64_t unk18;
    void* entries;
};

struct RoomSharedMap {
    RoomSharedMap() {}
    std::uint64_t unk00;
    RoomSharedTable table;
};

struct BSCullingProcess : NiCullingProcess {
    explicit BSCullingProcess(NiVisibleArray* visibleSet);
    ~BSCullingProcess() override;

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
