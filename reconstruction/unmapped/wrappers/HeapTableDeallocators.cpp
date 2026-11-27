// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original Scaleform-heap scalar deleting destructor wrappers.
// HeapTableDeallocators, ScaleformHeapAllocator, PolymorphicHeapObject and referenced globals: GUESS(low) STANDIN; original types unknown.
// Adapted bodies: none
// 0xd0c180 HeapTableDeallocators::Deleted0c180
// 0xd0c1d0 HeapTableDeallocators::Deleted0c1d0
// 0xd11c10 HeapTableDeallocators::Deleted11c10
// 0xd1ced0 HeapTableDeallocators::Deleted1ced0
// 0xd1d8d0 HeapTableDeallocators::Deleted1d8d0
// 0xd5b300 HeapTableDeallocators::Deleted5b300
// 0xd5b350 HeapTableDeallocators::Deleted5b350
// 0xd5b4d0 HeapTableDeallocators::Deleted5b4d0
// 0xd5b520 HeapTableDeallocators::Deleted5b520
// 0xd7d560 HeapTableDeallocators::Deleted7d560
// 0xdf1780 HeapTableDeallocators::Deletedf1780
// 0xdf17d0 HeapTableDeallocators::Deletedf17d0
// 0xe6e290 HeapTableDeallocators::Deletee6e290
// 0x11a3ef0 HeapTableDeallocators::Delete11a3ef0
// 0x11a4010 HeapTableDeallocators::Delete11a4010
// CI hash: 0xd0c180 ?Deleted0c180@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xd0c1d0 ?Deleted0c1d0@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xd11c10 ?Deleted11c10@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xd1ced0 ?Deleted1ced0@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xd1d8d0 ?Deleted1d8d0@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xd5b300 ?Deleted5b300@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xd5b350 ?Deleted5b350@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xd5b4d0 ?Deleted5b4d0@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xd5b520 ?Deleted5b520@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xd7d560 ?Deleted7d560@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xdf1780 ?Deletedf1780@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xdf17d0 ?Deletedf17d0@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0xe6e290 ?Deletee6e290@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0x11a3ef0 ?Delete11a3ef0@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
// CI hash: 0x11a4010 ?Delete11a4010@HeapTableDeallocators@@SAPEAXPEAUPolymorphicHeapObject@@I@Z
#include "HeapTableDeallocators.h"

namespace
{

constexpr unsigned int kDeleteMemoryFlag = 1u;
constexpr unsigned int kGlobalDeleteFlag = 4u;

// Scalar deleting destructor tail: restore base vftable and release via the Scaleform heap or sized ::operator delete.
inline void* DeletePolymorphicObject(
    PolymorphicHeapObject* object,
    void* baseVftable,
    unsigned int deleteFlags,
    unsigned long long objectSize)
{
    object->vftable = baseVftable;
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            g_scaleformHeap->Free(object);
        }
        else
        {
            GlobalSizedDelete(object, objectSize);
        }
    }
    return object;
}

} // namespace

void* HeapTableDeallocators::Deleted0c180(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a27c18, deleteFlags, 32ull);
}

void* HeapTableDeallocators::Deleted0c1d0(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a27c18, deleteFlags, 32ull);
}

void* HeapTableDeallocators::Deleted11c10(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a27c18, deleteFlags, 32ull);
}

void* HeapTableDeallocators::Deleted1ced0(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a27c18, deleteFlags, 32ull);
}

void* HeapTableDeallocators::Deleted1d8d0(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a27c18, deleteFlags, 32ull);
}

void* HeapTableDeallocators::Deleted5b300(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a2b938, deleteFlags, 32ull);
}

void* HeapTableDeallocators::Deleted5b350(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a2b938, deleteFlags, 24ull);
}

void* HeapTableDeallocators::Deleted5b4d0(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a2b938, deleteFlags, 32ull);
}

void* HeapTableDeallocators::Deleted5b520(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a2b938, deleteFlags, 32ull);
}

void* HeapTableDeallocators::Deleted7d560(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a2b938, deleteFlags, 32ull);
}

void* HeapTableDeallocators::Deletedf1780(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a3bc78, deleteFlags, 40ull);
}

void* HeapTableDeallocators::Deletedf17d0(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a3bc78, deleteFlags, 32ull);
}

void* HeapTableDeallocators::Deletee6e290(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1a3bc78, deleteFlags, 40ull);
}

void* HeapTableDeallocators::Delete11a3ef0(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1ab9490, deleteFlags, 16ull);
}

void* HeapTableDeallocators::Delete11a4010(PolymorphicHeapObject* object, unsigned int deleteFlags)
{
    return DeletePolymorphicObject(object, kBaseVftable1ab9430, deleteFlags, 16ull);
}
