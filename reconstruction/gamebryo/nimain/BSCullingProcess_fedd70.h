// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSCullingProcess, NiCullingProcess, Process1, Process2, SetFrustum, NiCamera, NiAVObject, NiVisibleArray, NiFrustum, NiFrustumPlanes, NiPlane, NiPoint3, BSPortalGraphEntry, BSCompoundFrustum, BSCPCullingType: CRASHLOGGER_PDB(59818@2026.10.24)
// useVirtualAppend, visibleSet, camera, frustum, planes, customCullPlanes, cameraRelatedUpdates, updateAccumulateFlag, ignorePreprocess, doCustomCullPlanes, enablePlaneOptimization, unk121, viewFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// objectArray, cullQueue, roomSharedMap, portalGraphEntry, cullMode, compoundFrustum, cullModeStack, cullModeStackIndex, recurseToGeometry, isGroupingAlphas, unk301D6, alphaGroups, alphaGroupIndex, alphaGroupStopIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// CullGeometry, BSTArrayHeapAllocator, BSTArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CullQueueEntry, CullQueueRing, CullQueue, RoomSharedMap, vslot00: GUESS(low) STANDIN
#pragma once

#include <cstdint>

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

    NiFrustumPlanes& operator=(const NiFrustumPlanes& other)
    {
        for (int i = 0; i < 6; ++i) {
            cullingPlanes[i].normal.x = other.cullingPlanes[i].normal.x;
            cullingPlanes[i].normal.y = other.cullingPlanes[i].normal.y;
            cullingPlanes[i].normal.z = other.cullingPlanes[i].normal.z;
            cullingPlanes[i].constant = other.cullingPlanes[i].constant;
        }
        activePlanes = other.activePlanes;
        basePlaneStates = other.basePlaneStates;
        unk68 = other.unk68;
        unk6C = other.unk6C;
        return *this;
    }
};

struct NiVisibleArray;
struct BSPortalGraphEntry;
struct BSCompoundFrustum;
struct BSCullingProcess;

struct NiAVObject {
    void CullGeometry(BSCullingProcess* process, std::uint32_t alphaGroupIndex);
};

struct NiCamera {
    std::uint64_t unk00[42];
    NiFrustum viewFrustum;
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
    virtual void Process1(NiAVObject* object, std::uint32_t alphaGroupIndex);
    virtual void Process2(NiCamera* camera, NiAVObject* scene, NiVisibleArray* visibleSet);

    void SetFrustum(const NiFrustum& view);

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

template<class T>
struct BSTArrayHeapAllocator {
    T* data;
    std::uint32_t capacity;
};

template<class T>
struct BSTArray : BSTArrayHeapAllocator<T> {
    std::uint32_t size;
};

struct CullQueueEntry {
    NiAVObject* object;
    int groupIndex;
    std::uint32_t flags;
};

struct CullQueueRing {
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

struct BSCullingProcess : NiCullingProcess {
    void Process2(NiCamera* camera, NiAVObject* scene, NiVisibleArray* visibleSet) override;

    BSTArray<NiAVObject*> objectArray;
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
    BSTArray<void*> alphaGroups;
    int alphaGroupIndex;
    std::uint32_t alphaGroupStopIndex;
};
