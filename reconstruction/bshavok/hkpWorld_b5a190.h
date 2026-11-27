// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; class, member and slot names from the labelled community sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// hkpWorld, getClosestPoints: GUESS(low); the name is the timer text the function logs
// hkpWorld::broadPhase, hkpWorld::kdTreeManager, hkpWorld::collisionInput, hkpWorld::collisionFilter: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpCollisionDispatcher, AgentFuncs, numAgent2Types, agent2Types, agent2TypesPred, agent2Func, createFunc, getPenetrationsFunc, getClosestPointFunc, linearCastFunc, isFlipped, isPredictive: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpTreeWorldManager, hkpTreeWorldManager::type, inactiveTree, kdTree, hkpTypedBroadPhaseHandle, id, hkpTypedBroadPhaseHandle::type, ownerOffset, objectQualityType, collisionFilterInfo, hkpTypedBroadPhaseHandlePair, a, b: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpCdBody, shape, shapeKey, motion, parent, hkpCollidable, hkpCollisionInput, dispatcher, weldClosestPoints, forceAcceptContactPoints, tolerance, hkpProcessCollisionInput: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpCollisionFilter, hkpCollidableCollidableFilter, isCollisionEnabled, hkReferencedObject, memSizeAndFlags, referenceCount, hkAabb, min, max, hkpBroadPhase, hkBool: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpShape, GetMaximumProjection, GetContainer, IsConvex, CalcSizeForSpu, GetAabbImpl, userData, hkpShape::type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// hkMemoryAllocator, BlockAlloc, BlockFree, BufAlloc, BufFree, hkReferencedObject::GetClassType, hkReferencedObject::CalcContentStatistics: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// hkContainerHeapAllocator, Allocator, hkArrayBase, kCapacityMask, data, size, hkInplaceArray::storage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// hkTimerCommand, name, time, hkTimerBeginListCommand, firstName, hkMonitorStream, start, current, capacity, end, g_hkMonitorStreamTlsIndex, hkTimerBeginList, hkTimerSplitList, hkTimerEndList: GUESS(low)
// g_timerListBroadPhase, g_timerListTrees, g_timer3AxisBroadPhase, g_timer3AxisNarrowPhase, g_timerAabbTreeBroadPhase, g_timerAabbTreeNarrowPhase, g_timerKdTreeBroadPhase, g_timerKdTreeNarrowPhase, g_timerEndList: GUESS(low)
// hkpBroadPhase::Unk_03-Unk_11, hkpTreeWorldManager::Unk_03: GUESS(low); slot names unknown, placeholders by slot
// hkpBroadPhase base hkReferencedObject: CRASHLOGGER_PDB(59818@2026.10.24)
// hkContainerTempAllocator, s_alloc, getAllocator, kDontDeallocate, kElementSize, capacityAndFlags, hkInplaceArray, hkTempArray: GUESS(low)
// getOwningObject, querySingleAabb, hasTrees, value, hkpTreeQueryAabbFunc, g_aabbTreeQueryAabb, g_kdTreeQueryAabb: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long a_index);

// a timer command in the monitor stream: a name that starts with the command code, then a time stamp
struct hkTimerCommand
{
    const char* name;  // 00
    std::uint32_t time;  // 08
};

// the command that opens a timer list also names the first timer of the list
struct hkTimerBeginListCommand : hkTimerCommand
{
    const char* firstName;  // 10
};

// the per-thread stream the timers write their commands to
struct hkMonitorStream
{
    hkTimerCommand* start;  // 00
    hkTimerCommand* current;  // 08
    hkTimerCommand* capacity;  // 10
    hkTimerCommand* end;  // 18
};

extern std::uint32_t g_hkMonitorStreamTlsIndex;

// timer names in the image, bound by address: the list names, the step names (broad and narrow phase) and the end mark
extern const char g_timerListBroadPhase[];
extern const char g_timerListTrees[];
extern const char g_timer3AxisBroadPhase[];
extern const char g_timer3AxisNarrowPhase[];
extern const char g_timerAabbTreeBroadPhase[];
extern const char g_timerAabbTreeNarrowPhase[];
extern const char g_timerKdTreeBroadPhase[];
extern const char g_timerKdTreeNarrowPhase[];
extern const char g_timerEndList[];

// open a timer list and start its first timer
inline void hkTimerBeginList(const char* a_list, const char* a_first)
{
    hkMonitorStream& stream = *static_cast<hkMonitorStream*>(TlsGetValue(g_hkMonitorStreamTlsIndex));
    if (stream.current < stream.end) {
        hkTimerBeginListCommand* command = static_cast<hkTimerBeginListCommand*>(stream.current);
        command->name = a_list;
        command->firstName = a_first;
        // the time stamp is the low half of the cpu counter
        command->time = static_cast<std::uint32_t>(__rdtsc());
        stream.current = command + 1;
    }
}

// end the running timer of a list and start the next one
inline void hkTimerSplitList(const char* a_name)
{
    hkMonitorStream& stream = *static_cast<hkMonitorStream*>(TlsGetValue(g_hkMonitorStreamTlsIndex));
    if (stream.current < stream.end) {
        hkTimerCommand* command = stream.current;
        command->name = a_name;
        // the time stamp is the low half of the cpu counter
        command->time = static_cast<std::uint32_t>(__rdtsc());
        stream.current = command + 1;
    }
}

// close a timer list
inline void hkTimerEndList()
{
    hkMonitorStream& stream = *static_cast<hkMonitorStream*>(TlsGetValue(g_hkMonitorStreamTlsIndex));
    if (stream.current < stream.end) {
        hkTimerCommand* command = stream.current;
        command->name = g_timerEndList;
        // the time stamp is the low half of the cpu counter
        command->time = static_cast<std::uint32_t>(__rdtsc());
        stream.current = command + 1;
    }
}

// a Havok memory allocator: containers free their buffers through it
class hkMemoryAllocator
{
public:
    virtual ~hkMemoryAllocator();  // 00
    virtual void* BlockAlloc(int a_numBytes) noexcept;  // 01
    virtual void BlockFree(void* a_ptr, int a_numBytes) noexcept;  // 02
    virtual void* BufAlloc(int& a_reqNumBytes) noexcept;  // 03
    virtual void BufFree(void* a_ptr, int a_numBytes) noexcept;  // 04
};

// the allocators containers use: each is one global allocator object, handed out as a plain memory allocator
struct hkContainerTempAllocator
{
    struct Allocator : hkMemoryAllocator
    {
    };

    static Allocator s_alloc;
    static hkMemoryAllocator& getAllocator() { return s_alloc; }
};

struct hkContainerHeapAllocator
{
    struct Allocator : hkMemoryAllocator
    {
    };

    static Allocator s_alloc;
    static hkMemoryAllocator& getAllocator() { return s_alloc; }
};

struct hkAabb
{
    __m128 min;  // 00
    __m128 max;  // 10
};

// the array header every Havok array starts with; the capacity word also carries two flag bits
template <class T>
struct hkArrayBase
{
    enum : int
    {
        kCapacityMask = 0x3FFFFFFF,
        kDontDeallocate = int(0x80000000),
        kElementSize = sizeof(T)
    };

    T* data;  // 00
    std::int32_t size;  // 08
    std::int32_t capacityAndFlags;  // 0C
};

// an array that starts in its own storage and frees a grown buffer through the heap allocator
template <class T, int N>
struct hkInplaceArray : hkArrayBase<T>
{
    hkInplaceArray()
    {
        this->data = storage;
        this->size = 0;
        this->capacityAndFlags = N | hkArrayBase<T>::kDontDeallocate;
    }
    ~hkInplaceArray()
    {
        this->size = 0;
        if (this->capacityAndFlags >= 0) {
            hkContainerHeapAllocator::getAllocator().BufFree(this->data, (this->capacityAndFlags & hkArrayBase<T>::kCapacityMask) * hkArrayBase<T>::kElementSize);
        }
    }

    alignas(16) T storage[N];  // 10
};

// an array whose buffer comes from the temp allocator
template <class T>
struct hkTempArray : hkArrayBase<T>
{
    hkTempArray()
    {
        this->data = nullptr;
        this->size = 0;
        this->capacityAndFlags = hkArrayBase<T>::kDontDeallocate;
    }
    ~hkTempArray()
    {
        this->size = 0;
        if (this->capacityAndFlags >= 0) {
            hkContainerTempAllocator::getAllocator().BufFree(this->data, (this->capacityAndFlags & hkArrayBase<T>::kCapacityMask) * hkArrayBase<T>::kElementSize);
        }
    }
};

// the base of every reference-counted Havok object
class hkReferencedObject
{
public:
    virtual ~hkReferencedObject();  // 00
    virtual const void* GetClassType() const;  // 01
    virtual void CalcContentStatistics(void* a_collector, const void* a_class) const;  // 02

    std::uint16_t memSizeAndFlags;  // 08
    std::int16_t referenceCount;  // 0A
    std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(hkReferencedObject) == 0x10, "hkReferencedObject size");

class hkpShape : public hkReferencedObject
{
public:
    virtual float GetMaximumProjection(const __m128& a_direction) const;  // 03
    virtual const void* GetContainer() const;  // 04
    virtual bool IsConvex() const;  // 05
    virtual std::int32_t CalcSizeForSpu(const void* a_input, std::int32_t a_spuBufferSizeLeft) const;  // 06
    virtual void GetAabbImpl(const void* a_localToWorld, float a_tolerance, hkAabb& a_out) const noexcept;  // 07

    void* userData;  // 10
    std::int32_t type;  // 18
    std::uint32_t pad1C;  // 1C
};
static_assert(sizeof(hkpShape) == 0x20, "hkpShape size");

struct hkpCdBody
{
    const hkpShape* shape;  // 00
    std::uint32_t shapeKey;  // 08
    std::uint32_t pad0C;  // 0C
    const void* motion;  // 10
    const hkpCdBody* parent;  // 18
};

struct hkpCollidable : hkpCdBody
{
};

// a broad phase handle sits inside the collidable that owns it and stores its own offset in that owner
struct hkpTypedBroadPhaseHandle
{
    // the object this handle is a member of
    const void* getOwningObject() const { return reinterpret_cast<const char*>(this) + ownerOffset; }

    std::uint32_t id;  // 00
    std::int8_t type;  // 04
    std::int8_t ownerOffset;  // 05
    std::int8_t objectQualityType;  // 06
    std::uint8_t pad07;  // 07
    std::uint32_t collisionFilterInfo;  // 08
};

struct hkpTypedBroadPhaseHandlePair
{
    hkpTypedBroadPhaseHandle* a;  // 00
    hkpTypedBroadPhaseHandle* b;  // 08
};

// the CrashLogger layout gives it the reference count fields, so slots 00-02 come from hkReferencedObject
class hkpBroadPhase : public hkReferencedObject
{
public:
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
    virtual void querySingleAabb(const hkAabb& a_aabb, hkInplaceArray<hkpTypedBroadPhaseHandlePair, 128>* a_hits) const noexcept;  // 12
};

class hkpTreeWorldManager : public hkReferencedObject
{
public:
    virtual void Unk_03();  // 03
    virtual bool hasTrees() const noexcept;  // 04

    std::int32_t type;  // 10
    std::uint32_t pad14;  // 14
    void* inactiveTree;  // 18
    void* kdTree;  // 20
};

// Havok's bool: one byte, built from a C++ bool
struct hkBool
{
    hkBool() {}
    hkBool(bool a_value) : value(a_value) {}
    operator bool() const { return value != 0; }

    char value;  // 00
};

class hkpCollidableCollidableFilter
{
public:
    virtual ~hkpCollidableCollidableFilter();  // 00
    virtual hkBool isCollisionEnabled(const hkpCollidable& a_a, const hkpCollidable& a_b) const noexcept;  // 01
};

class hkpCollisionFilter : public hkReferencedObject, public hkpCollidableCollidableFilter
{
};

struct hkpCollisionInput;

struct hkpCollisionDispatcher
{
    // the functions registered for one pair of shape types
    struct AgentFuncs
    {
        void* createFunc;  // 00
        void* getPenetrationsFunc;  // 08
        void (*getClosestPointFunc)(const hkpCdBody& a_a, const hkpCdBody& a_b, const hkpCollisionInput& a_input, void* a_collector);  // 10
        void* linearCastFunc;  // 18
        hkBool isFlipped;  // 20
        hkBool isPredictive;  // 21
    };

    std::uint8_t unknown000[0x2A0];  // 000
    std::int32_t numAgent2Types;  // 2A0
    std::uint8_t unknown2A4[0xC];  // 2A4
    std::uint8_t agent2Types[32][32];  // 2B0
    std::uint8_t agent2TypesPred[32][32];  // 6B0
    AgentFuncs agent2Func[64];  // AB0
};
static_assert(sizeof(hkpCollisionDispatcher::AgentFuncs) == 0x28, "AgentFuncs size");
static_assert(offsetof(hkpCollisionDispatcher, agent2Func) == 0xAB0, "hkpCollisionDispatcher layout");

struct hkpCollisionInput
{
    hkpCollisionDispatcher* dispatcher;  // 00
    std::int32_t weldClosestPoints;  // 08
    std::int32_t forceAcceptContactPoints;  // 0C
    float tolerance;  // 10
};

struct hkpProcessCollisionInput : hkpCollisionInput
{
};

using hkpTreeQueryAabbFunc = void (*)(void* a_tree, const hkAabb* a_aabb, void* a_hits);
extern hkpTreeQueryAabbFunc g_aabbTreeQueryAabb;
extern hkpTreeQueryAabbFunc g_kdTreeQueryAabb;

class hkpWorld
{
public:
    void getClosestPoints(const hkpCollidable* a_collidable, const hkpCollisionInput* a_input, void* a_collector) noexcept;  // compared: 0xb5a190

    std::uint8_t unknown00[0x88];  // 00
    hkpBroadPhase* broadPhase;  // 88
    hkpTreeWorldManager* kdTreeManager;  // 90
    std::uint8_t unknown98[0x30];  // 98
    hkpProcessCollisionInput* collisionInput;  // C8
    hkpCollisionFilter* collisionFilter;  // D0
};
