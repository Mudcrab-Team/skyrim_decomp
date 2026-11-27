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
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsshader/shadowscenenode.cpp:72 (NiPointer copy assignment)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00420000_o2.cpp:46326 (NiTPointerList GetNext)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 include/layout_support.h:375 (NiPointer constructor)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderconstantmap_decls.h:172 (NiPointer destructor)
// ShadowSceneNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// activeLights, shadowCasterLights, sceneGraphIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// queue arrays, padding: GUESS(low); shapes measured from the listing
// Code origin: original reconstruction from the pinned image listing; the sibling container shapes (BSTArray, NiPointer) are named in the units that include this
// Adapted bodies: BSShaderAccumulator::operator new (momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00680000_o2.cpp:17866, CC0-1.0), BSCullingProcess::operator new (momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00680000_o2.cpp:17866, CC0-1.0), NiCamera::operator new (momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00680000_o2.cpp:17866, CC0-1.0), NiPointer::operator= (momusdigital/fnv_decomp@2b07cb3e src/bsshader/shadowscenenode.cpp:72, CC0-1.0)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00680000_o2.cpp:17866 (BSShaderAccumulator operatornew: the class allocation forwarded to the engine allocator)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2_2.cpp:1754 (NiPointer copy assignment)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00660000_o2.cpp:35868 (NiCamera operator new: the class allocation forwarded to the engine allocator)
// Shared by the shadow units: the light, array and scope classes below sit ahead of ShadowSceneNode
// ShadowSceneNode_R5C: GUESS(low); the unit name only; the shadow declarations of the fifth round, batch C, a header of its own so the units merged against the earlier headers keep their closure
#pragma once

class ShadowSceneNode_R5C
{
};

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

    BSTArrayBase();
    ~BSTArrayBase();
    std::uint32_t AddUninitialized(const IAllocatorFunctor& a_allocator, std::uint32_t a_allocSize, std::uint32_t a_itemSize);

    std::uint32_t iSize;
};

class BSTArrayHeapAllocator
{
public:
    BSTArrayHeapAllocator();
    ~BSTArrayHeapAllocator();
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
    ~BSTArray() { Clear(true); }
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
    void Remove(std::uint32_t aiPos, std::uint32_t aiCount);
    BSTArrayIterator<T> erase(BSTArrayIterator<T> a_pos)
    {
        const std::uint32_t index = static_cast<std::uint32_t>(a_pos.pCurrent - &(*this)[0]);
        Remove(index, 1);
        if (!this->iSize) return BSTArrayIterator<T>(0);
        return BSTArrayIterator<T>(&(*this)[index]);
    }
    void Clear(bool abFree)
    {
        if (A::QBuffer()) {
            std::uint32_t count = this->iSize;
            T* pItem = static_cast<T*>(A::QBuffer());
            for (std::uint32_t i = 0; i < count; ++i) {
                pItem->~T();
                ++pItem;
            }
            if (abFree) {
                A::Deallocate();
            }
            this->iSize = 0;
        }
    }
    // noinline: the engine keeps SetSize as its own function that its callers call
    __declspec(noinline) bool SetSize(std::uint32_t aiSize);
    // noinline: the engine keeps this as its own function that SetSize calls
    __declspec(noinline) void ConstructDefaultItems(std::uint32_t aiStart, std::uint32_t aiCount);
    // noinline: the engine keeps this as its own function that SetSize calls
    __declspec(noinline) void DestructItems(std::uint32_t aiStart, std::uint32_t aiCount);
    template <class U>
    void Add(U a_arg)
    {
        std::uint32_t index = AddUninitialized();
        if (index != 0xffffffff) {
            T* item = static_cast<T*>(A::QBuffer()) + index;
            new (item) T(a_arg);
        }
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
inline bool BSTArray<T, A>::SetSize(std::uint32_t aiSize)
{
    bool bResult = true;
    if (aiSize == 0) {
        T* pItem = static_cast<T*>(A::QBuffer());
        if (pItem) {
            std::uint32_t count = this->iSize;
            for (std::uint32_t i = 0; i < count; ++i) {
                pItem->~T();
                ++pItem;
            }
        }
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
    long refCount;  // 08
    std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(NiRefHeader) == sizeof(NiRefObject), "NiRefHeader mirrors NiRefObject");

class NiRefCounted : public NiRefObject
{
public:
    // atomic count: every holder of the pointer shares this reference count
    void IncRefCount() { _InterlockedIncrement(&Header()->refCount); }
    std::uint32_t GetRefCount() { return static_cast<std::uint32_t>(Header()->refCount); }
    void DecRefCount()
    {
        // atomic count: the last holder to release deletes the object
        long count = _InterlockedDecrement(&Header()->refCount);
        if (count == 0) {
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
    NiPointer& operator=(const NiPointer& a_rhs) { return *this = a_rhs.m_pObject; }
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

inline void* AllocateGameObject(std::size_t a_size);
class NiVisibleArray;
class NiCamera;

// BSCullingProcess: GUESS(low); the lower slots are placeholders
// ~BSCullingProcess at slot 15: CRASHLOGGER_PDB(59818@2026.10.24)
class BSCullingProcess
{
public:
    explicit BSCullingProcess(NiVisibleArray* a_visibleSet);
    static void* operator new(std::size_t a_size) throw() { return AllocateGameObject(a_size); }
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
    virtual ~BSCullingProcess();  // 15

    std::uint8_t unknown08[0x18 - 0x08];
    NiCamera* camera;  // 18
    std::uint8_t unknown20[0xAC - 0x20];
    std::uint8_t customCullPlanes[0x70];  // AC
    std::uint8_t unknown11C[2];
    bool ignorePreprocess;  // 11E
    bool doCustomCullPlanes;  // 11F
    std::uint8_t unknown120[0x30190 - 0x120];
    void* unk30190;  // 30190
    std::uint8_t unknown30198[0x301F8 - 0x30198];
};

// NiPoint3: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0) STANDIN
struct NiPoint3
{
    NiPoint3() = default;
    NiPoint3(float a_x, float a_y, float a_z) : x(a_x), y(a_y), z(a_z) {}

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

// NiMatrix3, NiFrustum, UpdateTimeFlags: GUESS(low); shapes measured from the listing
struct NiMatrix3
{
    float entry[9];
};

struct NiFrustum
{
    explicit NiFrustum(bool a_ortho);
    float left;  // 00
    float right;  // 04
    float top;  // 08
    float bottom;  // 0C
    float nearPlane;  // 10
    float farPlane;  // 14
    std::uint32_t ortho;  // 18
};

struct UpdateTimeFlags
{
    float time;
    std::uint32_t flags;
};

// MemoryManager: STANDIN GUESS(low); the allocator object the image reads at 0x369a810, with its once-init guard at 0x369ac98
class MemoryManager
{
public:
    void* Allocate(std::uint32_t a_size, std::int32_t a_alignment, bool a_alignmentRequired);
};
// g_memoryManager, g_memoryManagerGuard, InitMemoryManager: GUESS(low)
extern MemoryManager g_memoryManager;
extern std::int32_t g_memoryManagerGuard;
void InitMemoryManager(MemoryManager* a_manager, std::int32_t* a_guard);

// NiColor: GUESS(low); three floats copied as one block
struct NiColor
{
    float red;
    float green;
    float blue;
};

// AllocateGameObject: GUESS(low); the engine allocator behind the class operators new below
inline void* AllocateGameObject(std::size_t a_size)
{
    if (g_memoryManagerGuard != 2) {
        InitMemoryManager(&g_memoryManager, &g_memoryManagerGuard);
    }
    return g_memoryManager.Allocate(static_cast<std::uint32_t>(a_size), 0, false);
}

// NiCamera, BSShaderAccumulator, NiLight: GUESS(low); counted objects the descriptor holds, only the fields the shadow code reads are named
class NiCamera : public NiRefCounted
{
public:
    NiCamera();
    static void* operator new(std::size_t a_size) throw() { return AllocateGameObject(a_size); }
    void SetFrustum(const NiFrustum& a_frustum);
    void UpdateObjectUpwards(UpdateTimeFlags* a_data);

    std::uint8_t unknown10[0x48 - 0x10];
    NiMatrix3 worldRotate;  // 48
    NiPoint3 worldTranslate;  // 6C
    std::uint8_t unknown78[0xA0 - 0x78];
    NiPoint3 worldPosition;  // A0
    std::uint8_t unknownAC[0x150 - 0xAC];
    NiFrustum frustum;  // 150
    std::uint8_t unknown16C[0x184 - 0x16C];
    float unk184;  // 184
};

class BSShaderAccumulator : public NiRefCounted
{
public:
    explicit BSShaderAccumulator(std::uint32_t a_mode);
    static void* operator new(std::size_t a_size) throw() { return AllocateGameObject(a_size); }
    void AccumulateSceneGraph(NiAVObject* a_root, bool a_filter);
    void ResetPasses();

    std::uint8_t unknown10[0x12C - 0x10];
    bool unk12C;  // 12C
    bool unk12D;  // 12D
    bool unk12E;  // 12E
    std::uint8_t unknown12F[0x148 - 0x12F];
    const void* unk148;  // 148
    std::uint32_t unk150;  // 150
    std::uint8_t unknown154[0x160 - 0x154];
    std::uint32_t passIndex;  // 160
    std::uint32_t passMask;  // 164
    std::uint32_t unk168;  // 168
    std::uint8_t unknown16C[0x180 - 0x16C];
};
static_assert(sizeof(BSShaderAccumulator) == 0x180, "BSShaderAccumulator size");

class NiLight : public NiRefCounted
{
public:
    std::uint8_t unknown10[0x48 - 0x10];
    NiMatrix3 worldRotate;  // 48
    NiPoint3 worldTranslate;  // 6C
    std::uint8_t unknown78[0x7C - 0x78];
    NiMatrix3 worldRotation;  // 7C
    NiPoint3 boundCenter;  // A0
    std::uint8_t unknownAC[0xF4 - 0xAC];
    std::uint32_t flags;  // F4
    std::uint8_t unknownF8[0x110 - 0xF8];
    NiColor ambient;  // 110
    NiColor diffuse;  // 11C
    float unknown128;  // 128
    std::uint8_t unknown12C[0x134 - 0x12C];
    float radius;  // 134
    std::uint8_t unknown138[0x158 - 0x138];
    void UpdateObjectUpwards(UpdateTimeFlags* a_data);

    NiLight();
    static void* operator new(std::size_t a_size) throw() { return AllocateGameObject(a_size); }
};
static_assert(sizeof(NiLight) == 0x158, "NiLight size");

// NiPlane: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0) STANDIN; the constructor is out of line
class NiPlane
{
public:
    NiPlane();

    float v[4];
};

// NiFrustumPlanes, NiCullingProcess, BSOcclusionShape layouts: CRASHLOGGER_PDB(59818@2026.10.24)
// NiFrustumPlanes(): GUESS(low); every plane starts active
class NiFrustumPlanes
{
public:
    NiFrustumPlanes() : activePlanes(0x3F), basePlaneStates(0x3F) {}

    NiPlane cullingPlanes[6];  // 00
    std::uint32_t activePlanes;  // 60
    std::uint32_t basePlaneStates;  // 64
    std::uint32_t unk68;  // 68
    std::uint32_t unk6C;  // 6C
};
static_assert(sizeof(NiFrustumPlanes) == 0x70, "NiFrustumPlanes size");

class NiVisibleArray;

// NiCullingProcess::SetFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCullingProcess::NiCullingProcess, NiCullingProcess::~NiCullingProcess: GUESS(low)
class NiCullingProcess
{
public:
    explicit NiCullingProcess(NiVisibleArray* a_visibleSet);
    virtual ~NiCullingProcess();

    void SetFrustum(const NiFrustum& a_frustum);

    bool useVirtualAppend;  // 08
    NiVisibleArray* visibleSet;  // 10
    NiCamera* camera;  // 18
    std::uint8_t unknown20[0x128 - 0x20];
};
static_assert(sizeof(NiCullingProcess) == 0x128, "NiCullingProcess size");

// BSOcclusionShape::IsOcclusionPlane at slot 25: GUESS(low)
class BSOcclusionShape : public NiObject
{
public:
    virtual bool IsOcclusionPlane();  // 25

    NiPoint3 translation;  // 10
    NiMatrix3 rotation;  // 1C
    std::uint32_t visibilityState;  // 40
};

// BSOcclusionPlane::InsidePlanes: CRASHLOGGER_PDB(59818@2026.10.24)
// BSOcclusionPlane::IsInFront: GUESS(low)
class BSOcclusionPlane : public BSOcclusionShape
{
public:
    bool InsidePlanes(const NiPoint3& a_point);
    bool IsInFront(const NiPoint3& a_point);
};

// NiTListItem, NiTPointerList: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0) STANDIN; only the walk is kept
template <class T>
struct NiTListItem
{
    NiTListItem* next;  // 00
    NiTListItem* previous;  // 08
    T element;  // 10
};

template <class T>
class NiTPointerList
{
public:
    NiTListItem<T>* GetHeadPos() const { return head; }
    T& GetNext(NiTListItem<T>*& a_pos) const
    {
        T& element = a_pos->element;
        a_pos = a_pos->next;
        return element;
    }

    NiTListItem<T>* head;  // 00
    NiTListItem<T>* tail;  // 08
    void* allocator;  // 10
};

// CullDescriptor, DispatchCullAndAccumulate: CRASHLOGGER_PDB(59818@2026.10.24)
// unk08, unk18, unk20, unk28, unk38, unk5D, unk5E, unk5F, unk60, CullRoot, SceneGraphEntry, SceneRootHolder, ResetPasses: GUESS(low); shapes measured from the listing
struct CullGeometryList
{
    CullGeometryList();
    static void* operator new(std::size_t a_size) throw() { return AllocateGameObject(a_size); }

    std::uint8_t unknown00[0x140];
};

struct CullRoot : public NiRefCounted
{
};

struct SceneRootHolder
{
    std::uint8_t unknown00[0x18];
    CullRoot* sceneRoot;  // 18
};

struct SceneGraphEntry
{
    std::uint8_t unknown00[0x118];
    SceneRootHolder* rootHolder;  // 118
};

struct CullDescriptor
{
    CullDescriptor();

    NiPointer<BSShaderAccumulator> accumulator;  // 00
    NiPointer<NiRefCounted> unk08;  // 08
    NiPointer<NiCamera> camera;  // 10
    const void* unk18;  // 18
    const void* unk20;  // 20
    const void* unk28;  // 28
    BSCullingProcess* geometryListProcess;  // 30
    const void* unk38;  // 38
    NiPointer<CullRoot> sceneRoot;  // 40
    const void* lightData;  // 48
    std::uint32_t cullMode;  // 50
    std::uint32_t pad54;  // 54
    std::uint32_t renderTargetIndex;  // 58
    std::uint8_t unk5C;  // 5C
    std::uint8_t unk5D;  // 5D
    std::uint8_t unk5E;  // 5E
    std::uint8_t unk5F;  // 5F
    std::uint8_t unk60;  // 60
    std::uint8_t unknown61[7];
};
static_assert(sizeof(CullDescriptor) == 0x68, "CullDescriptor size");

void DispatchCullAndAccumulate(CullDescriptor* a_descriptor, std::int32_t a_mode, std::int32_t a_flags);

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

// ShadowLightTail: GUESS(low); the member at 528 of a shadow light, destroyed out of line
// sceneAccumArray, shadowBiasScale, projectedBoundingBox, sceneGraphIndex, drawFocusShadows, NiRect: CRASHLOGGER_PDB(59818@2026.10.24)
struct NiRect
{
    std::uint32_t left;
    std::uint32_t right;
    std::uint32_t top;
    std::uint32_t bottom;
};

struct ShadowLightTail
{
    ~ShadowLightTail();
    BSTArrayHeapAllocator sceneAccumAllocator;  // 00; the allocator and count halves of the scene accumulation array
    BSTArrayBase sceneAccumCount;  // 10
    std::uint8_t unknown14[4];
    float shadowBiasScale;  // 18
    NiRect projectedBoundingBox;  // 1C
    std::int32_t sceneGraphIndex;  // 2C
    bool drawFocusShadows;  // 30
    std::uint8_t unknown31[0x560 - 0x559];
};

class BSLight : public NiRefCounted
{
public:
    ~BSLight() override;  // 00
    virtual bool Unk_02(NiLight* a_light);  // 02
    virtual bool Unk_03();  // 03

    BSLight();
    static void* operator new(std::size_t a_size) throw() { return AllocateGameObject(a_size); }

    void ClearGeometryList();
    void AttachObject(NiAVObject* a_object, bool a_arg2, bool a_arg3);
    void UpdateLODFadeAndCull(NiCamera* a_camera);
    void SetLight(NiLight* a_light);
    void ReleasePortalGraph();
    float GetLuminanceAtPoint(const NiPoint3& a_point, NiLight* a_ignore);
    bool Function1577a10(NiCamera* a_camera, NiCamera* a_lightCamera);

    std::uint8_t unknown010[0x4];
    float lodDimmer;  // 14
    std::uint8_t unknown018[0x2C];
    std::uint8_t unk44;  // 44
    std::uint8_t unknown045;
    std::uint8_t unk46;  // 46
    bool portalStrict;  // 47
    NiLight* light;  // 48
    NiPoint3 position;  // 50
    std::uint32_t frustumCull;  // 5C
    std::uint8_t unknown060[3];
    bool lodFade;  // 63
    std::uint8_t unknown064[0xD0 - 0x64];
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
    virtual bool Unk_06();  // 06
    virtual void Unk_07();  // 07
    virtual void Unk_08();  // 08
    virtual void Unk_09() = 0;  // 09
    virtual void Unk_0A() = 0;  // 0A
    virtual void Unk_0B();  // 0B
    virtual void Unk_0C();  // 0C

    BSShadowLight();
    void ReturnShadowmaps();
    void AccumulateShadow(ShadowmapDescriptor* a_descriptor, std::uint32_t* a_counter, BSTArray<BSCullingProcess*>* a_processes, std::uint32_t a_renderTarget);
    void RenderShadowmap(ShadowmapDescriptor* a_descriptor, std::uint32_t* a_arg, std::uint32_t a_flags);
    // noinline: the engine calls this out of line from SetShadowmapCount
    __declspec(noinline) void ReleaseShadowmapDescriptor(std::uint32_t a_index);
    void SetShadowmapCount(std::uint32_t a_count);

    std::uint32_t shadowMapCount;  // 140
    std::uint32_t unknown144;  // 144
    BSTArray<ShadowmapDescriptor> shadowmapDescriptors;  // 148
    ShadowmapDescriptor focusShadowmapDescriptors[4];  // 160
    std::uint32_t shadowmapIndex;  // 520
    std::uint8_t unknown524[4];
    ShadowLightTail tail;  // 528
};
static_assert(sizeof(BSShadowLight) == 0x560, "BSShadowLight size");

class BSShadowFrustumLight : public BSShadowLight
{
public:
    ~BSShadowFrustumLight() override;  // 00
    void Accumulate(const std::uint32_t* a_cascade, std::uint32_t a_count);
    void Render(std::uint32_t* a_arg);
    void SetLight(NiLight* a_light);
    BSShadowFrustumLight(float a_fov, float a_arg2, float a_nearPlane, float a_farPlane);
    BSShadowFrustumLight(float a_fovX, float a_fovY, float a_arg3, float a_nearPlane, float a_farPlane);
    bool UpdateCamera(NiCamera* a_camera);

    float unk560;  // 560
    float unk564;  // 564
    float unk568;  // 568
    float unk56C;  // 56C
    float unk570;  // 570
    std::uint8_t unknown574[0x578 - 0x574];
};
static_assert(sizeof(BSShadowFrustumLight) == 0x578, "BSShadowFrustumLight size");

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
    ~BSShadowDirectionalLight() override;  // 00
    void Accumulate(const std::uint32_t* a_cascade);
    void Render(std::uint32_t* a_arg);
    void ReturnShadowmaps();
    void SetupFocusShadowAccumulators();
    void TransformClipSpacePlanes(const void* a_arg1, const void* a_arg2);
    void UpdateSunDirection(NiPoint3* a_out);

    NiPoint3 sunDirection;  // 560
    std::uint8_t unknown56C[0x578 - 0x56C];
    NiPointer<NiCamera> cascadeCamera;  // 578
    BSTArray<BSCullingProcess*> cullingProcesses;  // 580
    std::uint8_t unknown598[0x5B0 - 0x598];
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

// PortalRoom, PortalNode, PortalCullContext, CullBound: GUESS(low); shapes measured from the listing
struct PortalRoom
{
    std::uint8_t unknown00[0x40];
    std::uint32_t kind;  // 40
};

struct PortalNode
{
    PortalNode* next;  // 00
    PortalNode* previous;  // 08
    PortalRoom* room;  // 10
};

struct PortalCullContext
{
    std::uint8_t unknown00[0x3C];
    float bounds[24];  // 3C
    std::uint32_t savedState;  // 9C
    std::uint8_t unknownA0[0x30198 - 0xA0];
    std::uint32_t mode;  // 30198
};

class CullBound : public NiRefCounted
{
public:
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual bool Contains(const float* a_bounds);  // 29

    bool Overlaps(const void* a_box, PortalCullContext* a_context, PortalRoom* a_room);

    std::uint32_t visibility;  // 10
};

struct BSPortalGraph
{
    std::uint8_t unknown00[0x10];
    NiTPointerList<BSOcclusionShape*> occlusionShapes;  // 10
    std::uint8_t unknown28[0x50 - 0x28];
    std::uint32_t unk50;  // 50

    void AddAlwaysRenderChild(NiAVObject* a_child);
    void RemoveAlwaysRenderChild(NiAVObject* a_child);

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

// FocusPoint: GUESS(low); a three-float point with the plain copy, the form the focus bounds are assigned through
struct FocusPoint
{
    FocusPoint(float a_x, float a_y, float a_z) : x(a_x), y(a_y), z(a_z) {}

    float x;
    float y;
    float z;
};

// FocusFrustum: GUESS(low); the counted bounds object a scene node keeps for the shadow focus, only the fields the setter writes are named
class FocusFrustum : public NiRefCounted
{
public:
    FocusFrustum();
    static void* operator new(std::size_t a_size) throw() { return AllocateGameObject(a_size); }

    std::uint8_t unknown10[0x38 - 0x10];
    FocusPoint centreA;  // 38
    FocusPoint centreB;  // 44
    float limitA;  // 50
    float limitB;  // 54
    float limitC;  // 58
    float limitD;  // 5C
    std::uint8_t unknown60[0x78 - 0x60];
    FocusPoint centreC;  // 78
    float scaleA;  // 84
    float scaleB;  // 88
    std::uint8_t unknown8C[0x90 - 0x8C];
};
static_assert(sizeof(FocusFrustum) == 0x90, "FocusFrustum size");

// NiRTTIView, ObjectFlagsView, CullPropertyView, CullGeometryView: GUESS(low); shapes measured from the listing
struct NiRTTIView
{
    const char* name;  // 00
    const NiRTTIView* base;  // 08
};

// g_niLightRTTI: GUESS(low); the run-time type record of the light class
extern NiRTTIView g_niLightRTTI;

// g_lightRadiusRTTI, LightRadiusView: GUESS(low); a light subclass whose three-float radius at 128 the walk resets
extern NiRTTIView g_lightRadiusRTTI;

struct LightRadiusView
{
    std::uint8_t unknown00[0x128];
    FocusPoint radius;  // 128
};

struct ObjectFlagsView
{
    std::uint8_t unknown00[0xF4];
    std::uint32_t flags;  // F4
};

struct CullPropertyView
{
    std::uint8_t unknown00[0x18];
    CullBound* bound;  // 18
};

struct CullGeometryView : public NiAVObject
{
    std::uint8_t unknown110[0x128 - 0x110];
    CullPropertyView* shaderProperty;  // 128
    std::uint8_t unknown130[4];
    std::uint32_t visibilityStamp;  // 134
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
    std::uint32_t AddLightsBelow(NiNode* a_node, float a_radius);
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
    void TestCachedAABBVisibility(CullBound* a_bound, const void* a_box, PortalCullContext* a_context);
    // noinline: the engine calls this out of line from its callers
    __declspec(noinline) void EnableLight(BSLight* a_light);
    void AttachShadowLight(BSLight* a_light, ShadowLightTail* a_tail, bool a_focus);
    void AccumulateLights(BSLight* a_light, std::uint32_t a_arg, bool a_focus);
    void UpdateLightList(BSTArray<NiPointer<BSLight>>* a_lights, NiCamera* a_camera);
    void UpdateOcclusionPlaneVisibility(NiCamera* a_camera);
    float GetLuminanceAtPoint(const NiPoint3& a_point, std::uint32_t& a_lightCount, float& a_ambient, float& a_diffuse, NiLight* a_ignore, std::uint32_t a_shadowMask);
    void BeginShadowFrame(ShadowFrameSource* a_source);
    void* FillShadowScratch(int a_value);
    void ReplaceShadowCasters(BSShadowLight* a_light, std::uint32_t a_start, std::uint32_t a_count);
    void UpdateActiveLightsLODFadeAndCull(NiCamera* a_camera);
    void QueueLightRemoveByNode(NiLight* a_light);
    void QueueLightRemoveUnscoped(BSLight* a_light);
    void AttachSceneObjectsToLight(BSLight* a_light);
    void SetLightNodeFlags(NiNode* a_node, bool a_set, bool a_remove);
    void TestGeometryVisibility(CullGeometryView* a_object, const void* a_box, PortalCullContext* a_context);
    void SetFocusFrustum(FocusFrustum* a_frustum);
    void SetCloudLight(NiLight* a_light);
    void SetSunLight(NiLight* a_light);
    void AttachObjectToList(NiAVObject* a_object, bool a_secondary);
    void UpdateAlwaysRenderObject(NiAVObject* a_object, bool a_notify, bool a_add);

    std::uint8_t unknown128[8];
    BSTArray<NiPointer<BSLight>> activeLights;  // 130
    BSTArray<NiPointer<BSLight>> shadowLights;  // 148
    BSTArray<NiPointer<BSLight>> queuedAdd;  // 160
    BSTArray<NiPointer<BSLight>> queuedRemove;  // 178
    ShadowLightArray lightQueueRemove;  // 190
    BSSpinLock lightQueueLock;  // 1A8
    ShadowObjectArray alwaysRenderObjects;  // 1B0
    ShadowObjectArray particleNodes;  // 1C8
    ShadowObjectArray attachedNodes;  // 1E0
    BSSpinLock objectListLock;  // 1F8
    BSLight* sunLight;  // 200
    BSLight* cloudLight;  // 208
    BSShadowDirectionalLight* shadowDirLight;  // 210
    std::uint8_t sceneGraphIndex;  // 218
    std::uint8_t unknown219[0x220 - 0x219];
    NiPointer<FocusFrustum> focusFrustum;  // 220
    BSPortalGraph* portalGraph;  // 228
    BSTArray<BSShadowLight*> shadowCasterLights;  // 230
    std::uint8_t unknown248[0x300 - 0x248];
    bool allowLightRemoveQueues;  // 300
    std::uint8_t unknown301[0x308 - 0x301];
};
static_assert(sizeof(ShadowSceneNode) == 0x308, "ShadowSceneNode size");
