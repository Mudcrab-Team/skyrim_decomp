// Source exposure: mixed (community headers, sibling declarations and the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLight, BSShadowLight, BSSpinLock, LIGHT_CREATE_PARAMS: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// frustumCull, shadowmapIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// view structs, padding: GUESS(low); shapes measured from the listing
// BSAutoLock: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; the name and the lock-guard shape
// NiPoint3, NiPlane: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0) STANDIN; bodies listed below
// MemoryContextScope: GUESS(low); the scope destructor body is listed below
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380 (NiPoint3 operator=, a member-wise copy)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00c80000_o2.cpp:5505 (scope destructor)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00c80000_o2.cpp:6643 (scope destructor)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/tile3d.cpp:33 (NiPointer constructor)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 include/layout_support.h:375 (NiPointer constructor)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderconstantmap_decls.h:172 (NiPointer destructor)
// ShadowSceneNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// activeLights, shadowCasterLights, sceneGraphIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// queue arrays, padding: GUESS(low); shapes measured from the listing
// Code origin: original reconstruction from the pinned image listing; the sibling container shapes (BSTArray, NiPointer) are named in the units that include this
// Shared by the shadow units: the light, array and scope classes below sit ahead of ShadowSceneNode
#pragma once

#include <cstdint>
#include <intrin.h>
#include <new>
#include "declarations/NiNode.h"
#include "declarations/NiRefObject.h"

class BSLight;
class BSPortalGraph;
class BSLensFlareRenderData;

// BSTArray, BSTArrayBase, BSTArrayHeapAllocator, BSTArrayAllocatorFunctor, BSTArrayIterator: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; declarations
// pBuffer, iAllocSize, iSize: GUESS(low)
class BSTArrayBase
{
public:
    class IAllocatorFunctor
    {
    public:
        virtual bool Allocate(std::uint32_t, std::uint32_t) const = 0;
        virtual bool Reallocate(std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t) const = 0;
        virtual void Deallocate() const = 0;
        virtual ~IAllocatorFunctor() {}
    };

    std::uint32_t AddUninitialized(const IAllocatorFunctor& a_allocator, std::uint32_t a_allocSize, std::uint32_t a_itemSize);

    std::uint32_t iSize;
};

class BSTArrayHeapAllocator
{
public:
    bool Allocate(std::uint32_t a_count, std::uint32_t a_itemSize);
    bool Reallocate(std::uint32_t a_newCount, std::uint32_t a_oldCount, std::uint32_t a_copyFrom, std::uint32_t a_copyCount, std::uint32_t a_itemSize);
    void Deallocate();
    void* QBuffer();
    std::uint32_t QAllocSize() const;

    void* pBuffer;
    std::uint32_t iAllocSize;
};

inline void* BSTArrayHeapAllocator::QBuffer() { return pBuffer; }
inline std::uint32_t BSTArrayHeapAllocator::QAllocSize() const { return iAllocSize; }

template <class A>
struct BSTArrayAllocatorFunctor : public BSTArrayBase::IAllocatorFunctor
{
public:
    BSTArrayAllocatorFunctor(A* a_allocator) : pAllocator(a_allocator) {}
    virtual ~BSTArrayAllocatorFunctor() {}
    virtual bool Allocate(std::uint32_t a_count, std::uint32_t a_itemSize) const { return pAllocator->Allocate(a_count, a_itemSize); }
    virtual bool Reallocate(std::uint32_t a_newCount, std::uint32_t a_oldCount, std::uint32_t a_copyFrom, std::uint32_t a_copyCount, std::uint32_t a_itemSize) const
    {
        return pAllocator->Reallocate(a_newCount, a_oldCount, a_copyFrom, a_copyCount, a_itemSize);
    }
    virtual void Deallocate() const { pAllocator->Deallocate(); }

    A* pAllocator;
};

template <class T>
class BSTArrayIterator
{
public:
    BSTArrayIterator(T* a_current) : pCurrent(a_current) {}
    BSTArrayIterator(const BSTArrayIterator& a_other) : pCurrent(a_other.pCurrent) {}
    ~BSTArrayIterator() {}
    T& operator*() const { return *pCurrent; }
    BSTArrayIterator& operator++() { ++pCurrent; return *this; }
    bool operator!=(const BSTArrayIterator& a_rhs) const { return pCurrent != a_rhs.pCurrent; }

    T* pCurrent;
};

template <class T, class A = BSTArrayHeapAllocator>
class BSTArray : public A, public BSTArrayBase
{
public:
    BSTArrayIterator<T> begin()
    {
        if (!this->iSize) return BSTArrayIterator<T>(0);
        return BSTArrayIterator<T>(static_cast<T*>(A::QBuffer()));
    }
    BSTArrayIterator<T> end()
    {
        if (!this->iSize) return BSTArrayIterator<T>(0);
        return BSTArrayIterator<T>(static_cast<T*>(A::QBuffer()) + this->iSize);
    }
    T& operator[](std::uint32_t a_index) { return static_cast<T*>(A::QBuffer())[a_index]; }
    std::uint32_t QAllocSize() const { return A::QAllocSize(); }
    std::uint32_t AddUninitialized()
    {
        return BSTArrayBase::AddUninitialized(BSTArrayAllocatorFunctor<A>(this), QAllocSize(), sizeof(T));
    }
    std::uint32_t Add(const T& a_item)
    {
        std::uint32_t index = AddUninitialized();
        if (index != 0xffffffff) {
            T* item = static_cast<T*>(A::QBuffer()) + index;
            new (item) T(a_item);
        }
        return index;
    }
    void Clear(bool abFree);
    // noinline: the engine keeps SetSize as its own function that its callers call
    __declspec(noinline) bool SetSize(std::uint32_t aiSize);
    // noinline: the engine keeps this as its own function that SetSize calls
    __declspec(noinline) void ConstructDefaultItems(std::uint32_t aiStart, std::uint32_t aiCount);
    void DestructItems(std::uint32_t aiStart, std::uint32_t aiCount);
    template <class U>
    std::uint32_t Add(U a_arg)
    {
        std::uint32_t index = AddUninitialized();
        if (index != 0xffffffff) {
            T* item = static_cast<T*>(A::QBuffer()) + index;
            new (item) T(a_arg);
        }
        return index;
    }
};

template <class T, class A>
inline void BSTArray<T, A>::ConstructDefaultItems(std::uint32_t aiStart, std::uint32_t aiCount)
{
    T* pItem = static_cast<T*>(A::QBuffer()) + aiStart;
    for (std::uint32_t i = 0; i < aiCount; ++i) {
        new (pItem) T;
        ++pItem;
    }
}

template <class T, class A>
inline void BSTArray<T, A>::DestructItems(std::uint32_t aiStart, std::uint32_t aiCount)
{
    T* pItem = static_cast<T*>(A::QBuffer()) + aiStart;
    for (std::uint32_t i = 0; i < aiCount; ++i) {
        pItem->~T();
        ++pItem;
    }
}

template <class T, class A>
inline void BSTArray<T, A>::Clear(bool abFree)
{
    if (A::QBuffer()) {
        DestructItems(0, this->iSize);
        if (abFree) {
            A::Deallocate();
        }
        this->iSize = 0;
    }
}

template <class T, class A>
inline bool BSTArray<T, A>::SetSize(std::uint32_t aiSize)
{
    bool bResult = true;
    if (aiSize == 0) {
        Clear(false);
    } else if (aiSize == this->iSize) {
        bResult = true;
    } else if (aiSize > QAllocSize()) {
        if (!QAllocSize()) {
            bResult = A::Allocate(aiSize, sizeof(T));
        } else {
            bResult = A::Reallocate(aiSize, this->iSize, 0, 0, sizeof(T));
        }
        if (bResult) {
            ConstructDefaultItems(this->iSize, aiSize - this->iSize);
        }
    } else if (aiSize < this->iSize) {
        DestructItems(aiSize, this->iSize - aiSize);
    } else {
        ConstructDefaultItems(this->iSize, aiSize - this->iSize);
    }
    if (bResult) {
        this->iSize = aiSize;
    }
    return bResult;
}

// BSSpinLock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

class BSSpinLock
{
public:
    void Unlock();

    std::uint32_t owningThread;
    std::uint32_t lockCount;
};

// BSAutoLock: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; the constructor is out of line, the destructor releases inline
class BSAutoLock
{
public:
    explicit BSAutoLock(BSSpinLock* a_lock) noexcept;
    ~BSAutoLock()
    {
        if (lock) {
            lock->Unlock();
        }
    }

    BSSpinLock* lock;
};

// g_memoryContext, MemoryContextScope: GUESS(low); a per-thread allocation category saved, set and restored
extern __declspec(thread) std::uint32_t g_memoryContext;

class MemoryContextScope
{
public:
    explicit MemoryContextScope(std::uint32_t a_value) : saved(g_memoryContext) { g_memoryContext = a_value; }
    ~MemoryContextScope() { g_memoryContext = saved; }

private:
    std::uint32_t saved;
};

// NiPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_pObject: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
// Acquire, Release, copy shape: GUESS(low); two stores of the pointer in the copy constructor
// NiRefCounted: GUESS(low); the reference count at 08 with the engine's increment and release-on-zero
// NiRefHeader: GUESS(low); the first sixteen bytes of a counted object, the count sits at 08
struct NiRefHeader
{
    void* vtable;  // 00
    volatile long refCount;  // 08
    std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(NiRefHeader) == sizeof(NiRefObject), "NiRefHeader mirrors NiRefObject");

class NiRefCounted : public NiRefObject
{
public:
    // atomic count: every holder of the pointer shares this reference count
    void IncRefCount() { _InterlockedIncrement(&Header()->refCount); }
    void DecRefCount()
    {
        // atomic count: the last holder to release deletes the object
        if (_InterlockedDecrement(&Header()->refCount) == 0) {
            DeleteThis();
        }
    }

private:
    NiRefHeader* Header() { return reinterpret_cast<NiRefHeader*>(this); }
};

template <class T>
class NiPointer
{
public:
    NiPointer(const NiPointer& ptr) : m_pObject(ptr.m_pObject) { m_pObject = Acquire(ptr.m_pObject); }
    NiPointer() : m_pObject(0) {}
    NiPointer(T* pObject)
    {
        m_pObject = pObject;
        if (m_pObject) {
            m_pObject->IncRefCount();
        }
    }
    ~NiPointer() { Release(m_pObject); }
    operator T*() const { return m_pObject; }
    T* operator->() const { return m_pObject; }
    NiPointer& operator=(T* pObject)
    {
        if (m_pObject != pObject) {
            T* pOld = m_pObject;
            m_pObject = Acquire(pObject);
            Release(pOld);
        }
        return *this;
    }

    T* Acquire(T* pObject)
    {
        if (pObject) {
            pObject->IncRefCount();
        }
        return pObject;
    }
    void Release(T* pObject)
    {
        if (pObject) {
            pObject->DecRefCount();
        }
    }

    T* m_pObject;
};

// BSCullingProcess: GUESS(low); a polymorphic object released through slot 15, the lower slots are placeholders
class BSCullingProcess
{
public:
    virtual void Unk_00();  // 00
    virtual void Unk_01();  // 01
    virtual void Unk_02();  // 02
    virtual void Unk_03();  // 03
    virtual void Unk_04();  // 04
    virtual void Unk_05();  // 05
    virtual void Unk_06();  // 06
    virtual void Unk_07();  // 07
    virtual void Unk_08();  // 08
    virtual void Unk_09();  // 09
    virtual void Unk_0A();  // 0A
    virtual void Unk_0B();  // 0B
    virtual void Unk_0C();  // 0C
    virtual void Unk_0D();  // 0D
    virtual void Unk_0E();  // 0E
    virtual void Unk_0F();  // 0F
    virtual void Unk_10();  // 10
    virtual void Unk_11();  // 11
    virtual void Unk_12();  // 12
    virtual void Unk_13();  // 13
    virtual void Unk_14();  // 14
    virtual void Unk_15(std::uint32_t a_flag);  // 15
};

// NiCamera, BSShaderAccumulator: GUESS(low); counted objects the descriptor holds, no body reads their layout
class NiCamera : public NiRefCounted
{
};

class BSShaderAccumulator : public NiRefCounted
{
};

// NiLight: GUESS(low); the light node, only the float at 128 is read here
class NiLight
{
public:
    std::uint8_t unknown00[0x128];
    float unknown128;  // 128
};

// NiPoint3: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0) STANDIN
struct NiPoint3
{
    NiPoint3& operator=(const NiPoint3& a_rhs)
    {
        x = a_rhs.x;
        y = a_rhs.y;
        z = a_rhs.z;
        return *this;
    }

    float x;
    float y;
    float z;
};

// NiPlane: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0) STANDIN; the constructor is out of line
class NiPlane
{
public:
    NiPlane();

    float v[4];
};

// ShadowmapDescriptor: CRASHLOGGER_PDB(59818@2026.10.24)
// BSShadowLight::Data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// camera, shaderAccumulator, cullingMode, renderTarget, shadowmapIndex, clipPlanes: CRASHLOGGER_PDB(59818@2026.10.24)
// unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE8, unkE9: GUESS(low)
struct ShadowmapDescriptor
{
    ShadowmapDescriptor();
    ~ShadowmapDescriptor() noexcept;

    float lightTransform[16];  // 00
    NiPointer<NiCamera> camera;  // 40
    NiPointer<BSShaderAccumulator> shaderAccumulator;  // 48
    std::uint32_t cullingMode;  // 50
    std::int32_t renderTarget;  // 54
    std::uint32_t shadowmapIndex;  // 58
    NiPlane clipPlanes[6];  // 5C
    std::uint32_t unkBC;  // BC
    std::uint32_t unkC0;  // C0
    std::uint32_t unkC4;  // C4
    std::uint32_t unkC8;  // C8
    float unkCC;  // CC
    std::uint32_t unkD0;  // D0
    std::uint32_t unkD4;  // D4
    std::uint32_t unkD8;  // D8
    std::uint32_t unkDC;  // DC
    BSCullingProcess* cullingProcess;  // E0
    std::uint8_t unkE8;  // E8
    std::uint8_t unkE9;  // E9
    std::uint8_t padEA[6];  // EA
};
static_assert(sizeof(ShadowmapDescriptor) == 0xF0, "ShadowmapDescriptor size");

class BSLight : public NiRefCounted
{
public:
    ~BSLight() override;  // 00
    virtual bool Unk_02(NiLight* a_light);  // 02
    virtual bool Unk_03();  // 03

    void ClearGeometryList();
    void AttachObject(NiAVObject* a_object, bool a_arg2, bool a_arg3);

    std::uint8_t unknown010[0x38];
    NiLight* light;  // 48
    std::uint8_t unknown050[0x5C - 0x50];
    std::uint32_t frustumCull;  // 5C
    std::uint8_t unknown060[0xD0 - 0x60];
    std::uint8_t unk0D0;  // D0
    std::uint8_t unknown0D1[0x120 - 0xD1];
    BSPortalGraph* portalGraph;  // 120
    BSCullingProcess* cullingProcess;  // 128
    std::uint8_t unknown130[0x140 - 0x130];
};
static_assert(sizeof(BSLight) == 0x140, "BSLight size");

class BSShadowLight : public BSLight
{
public:
    ~BSShadowLight() override;  // 00
    virtual void Unk_04();  // 04
    virtual void Unk_05();  // 05
    virtual void Unk_06();  // 06
    virtual void Unk_07();  // 07
    virtual void Unk_08();  // 08
    virtual void Unk_09() = 0;  // 09
    virtual void Unk_0A() = 0;  // 0A
    virtual void Unk_0B();  // 0B
    virtual void Unk_0C();  // 0C

    void ReturnShadowmaps();
    // noinline: the engine calls this out of line from SetShadowmapCount
    __declspec(noinline) void ReleaseShadowmapDescriptor(std::uint32_t a_index);
    void SetShadowmapCount(std::uint32_t a_count);

    std::uint32_t shadowMapCount;  // 140
    std::uint32_t unknown144;  // 144
    BSTArray<ShadowmapDescriptor> shadowmapDescriptors;  // 148
    ShadowmapDescriptor focusShadowmapDescriptors[4];  // 160
    std::uint32_t shadowmapIndex;  // 520
    std::uint8_t unknown524[0x560 - 0x524];
};
static_assert(sizeof(BSShadowLight) == 0x560, "BSShadowLight size");

class BSShadowParabolicLight : public BSShadowLight
{
public:
    ~BSShadowParabolicLight() override;  // 00
    void Render(void* a_arg);
    // noinline: the engine calls this out of line from Render
    __declspec(noinline) void RenderCascade(ShadowmapDescriptor* a_descriptor, void* a_arg, std::uint32_t a_flags);
};

class BSShadowDirectionalLight : public BSShadowLight
{
public:
    void ReturnShadowmaps();
    void TransformClipSpacePlanes(const void* a_arg1, const void* a_arg2);
    void UpdateSunDirection(NiPoint3* a_out);

    NiPoint3 sunDirection;  // 560
    std::uint8_t unknown56C[0x5B0 - 0x56C];
    float sunDirectionTime;  // 5B0
    std::uint32_t sunDirectionMode;  // 5B4
};

// ShadowLightArray: GUESS(low); the out-of-line append of a counted light reference
struct ShadowLightArray
{
    void Append(BSLight* a_light);

    void* _data;
    std::uint32_t _capacity;
    std::uint32_t pad0C;
    std::uint32_t _size;
    std::uint32_t pad14;
};

struct ShadowObjectArray
{
    void Append(NiAVObject* a_object);

    void* _data;
    std::uint32_t _capacity;
    std::uint32_t pad0C;
    std::uint32_t _size;
    std::uint32_t pad14;
};

struct BSShaderPropertyLightData
{
    void RemoveGeometryFromLights(NiAVObject* a_geometry);
};

struct ShaderPropertyView
{
    std::uint8_t unknown00[0x70];
    BSShaderPropertyLightData* lightData;  // 70
};

struct GeometryView : public NiAVObject
{
    std::uint8_t unknown110[0x128 - 0x110];
    ShaderPropertyView* shaderProperty;  // 128
};

struct NiNodeChildren
{
    void* vtable;  // 00
    NiAVObject** data;  // 08
    std::uint16_t capacity;  // 10
    std::uint16_t emptyRunStart;  // 12
    std::uint16_t size;  // 14
    std::uint16_t growBy;  // 16
};

// NiNodeView: GUESS(low); a node seen as its base plus the child array at 110
struct NiNodeView : public NiAVObject
{
    NiNodeChildren children;  // 110
};
static_assert(sizeof(NiNodeView) == 0x128, "NiNodeView child array");

struct ShadowFrameSource
{
    void Prepare();

    std::uint8_t unknown00[0x18];
    void* view;  // 18
};

struct BSPortalGraph
{
    std::uint32_t GetAlwaysRenderCount();
    NiAVObject* GetAlwaysRenderAt(std::uint32_t a_index);
};

struct LIGHT_CREATE_PARAMS
{
    std::uint8_t unk00;  // 00
    std::uint8_t unk01 = 0;  // 01
    bool portalStrict = false;  // 02
    bool affectLand = true;  // 03
    std::uint8_t unk04 = 1;  // 04
    bool neverFades = true;  // 05
    float fov = 1.0f;  // 08
    float falloff = 1.0f;  // 0C
    float nearDistance = 5.0f;  // 10
    float depthBias;  // 14
    std::uint32_t unk18 = 0;  // 18
    NiAVObject* objectNode = nullptr;  // 20
    BSLensFlareRenderData* lensFlareData = nullptr;  // 28
};

class ShadowSceneNode : public NiNode
{
public:
    void ClearShadowCasterArray();
    BSShadowLight* GetShadowCasterLightArrayEntry(std::uint32_t a_index);
    BSLight* GetActiveLightAt(std::uint32_t a_index);
    BSLight* GetShadowCasterLightByIndex(std::uint32_t a_index);
    // noinline: the engine calls this out of line from its callers
    __declspec(noinline) BSLight* FindActiveLight(NiLight* a_light);
    BSLight* FindQueuedAddLight(NiLight* a_light);
    std::uint16_t CountLitShadowLights();
    BSLight* AddLight(NiLight* a_light, bool a_flag);
    void AddLight(BSLight* a_light);
    BSLight* AddLight(NiLight* a_light, LIGHT_CREATE_PARAMS* a_params);
    void ClearLights_Flagged(bool a_clear, bool a_keepArrays);
    // noinline: the engine calls this out of line from its callers
    __declspec(noinline) void ClearLightArrays();
    void RemoveLightByNode(NiLight* a_light);
    // noinline: the engine calls this out of line from its callers
    __declspec(noinline) void QueueLightAdd(const NiPointer<BSLight>& a_light);
    // noinline: the engine calls this out of line from its callers, which tail-call it
    __declspec(noinline) void QueueLightRemove(BSLight* a_light);
    void TryQueueLightRemove(NiLight* a_light);
    void AttachObject(NiAVObject* a_object);
    void ClearShadowLightShadowmaps();
    void UnlinkLightFromPortalGraph(NiAVObject* a_object);
    void UnlinkChildLights(NiNode* a_node);
    void CollectLightingShaderGeometry(void* a_visitor);
    void CollectLitGeometry();

    std::uint8_t unknown128[8];
    BSTArray<NiPointer<BSLight>> activeLights;  // 130
    BSTArray<NiPointer<BSLight>> shadowLights;  // 148
    BSTArray<NiPointer<BSLight>> queuedAdd;  // 160
    BSTArray<NiPointer<BSLight>> queuedRemove;  // 178
    ShadowLightArray lightQueueRemove;  // 190
    BSSpinLock lightQueueLock;  // 1A8
    std::uint8_t unknown1B0[0x1C8 - 0x1B0];
    ShadowObjectArray particleNodes;  // 1C8
    std::uint8_t unknown1E0[0x1F8 - 0x1E0];
    BSSpinLock objectListLock;  // 1F8
    std::uint8_t unknown200[0x210 - 0x200];
    BSShadowDirectionalLight* shadowDirLight;  // 210
    std::uint8_t sceneGraphIndex;  // 218
    std::uint8_t unknown219[0x228 - 0x219];
    BSPortalGraph* portalGraph;  // 228
    BSTArray<BSShadowLight*> shadowCasterLights;  // 230
    std::uint8_t unknown248[0x300 - 0x248];
    bool allowLightRemoveQueues;  // 300
    std::uint8_t unknown301[0x308 - 0x301];
};
static_assert(sizeof(ShadowSceneNode) == 0x308, "ShadowSceneNode size");
