// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapTripleTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0xd11b80 HeapTripleTableDeallocators::Deleted11b80
// 0xd11d70 HeapTripleTableDeallocators::Deleted11d70
// 0xd6b220 HeapTripleTableDeallocators::Deleted6b220
// 0xd6b370 HeapTripleTableDeallocators::Deleted6b370
// 0xd876e0 HeapTripleTableDeallocators::Deleted876e0
// 0xd87830 HeapTripleTableDeallocators::Deleted87830
// 0xda27c0 HeapTripleTableDeallocators::Deleteda27c0
// 0xda2910 HeapTripleTableDeallocators::Deleteda2910
// 0xda4d10 HeapTripleTableDeallocators::Deleteda4d10
// 0xda4e60 HeapTripleTableDeallocators::Deleteda4e60
// 0xda8350 HeapTripleTableDeallocators::Deleteda8350
// 0xda84a0 HeapTripleTableDeallocators::Deleteda84a0
// 0xdaa750 HeapTripleTableDeallocators::Deletedaa750
// 0xdaa8a0 HeapTripleTableDeallocators::Deletedaa8a0
// 0xdaecf0 HeapTripleTableDeallocators::Deletedaecf0
// 0xdaee40 HeapTripleTableDeallocators::Deletedaee40
// 0xdb0340 HeapTripleTableDeallocators::Deletedb0340
// 0xdb0490 HeapTripleTableDeallocators::Deletedb0490
// 0xdb5ee0 HeapTripleTableDeallocators::Deletedb5ee0
// 0xdb6030 HeapTripleTableDeallocators::Deletedb6030
// 0xdb79b0 HeapTripleTableDeallocators::Deletedb79b0
// 0xdb7b00 HeapTripleTableDeallocators::Deletedb7b00
// 0xdb8ba0 HeapTripleTableDeallocators::Deletedb8ba0
// 0xdb8cf0 HeapTripleTableDeallocators::Deletedb8cf0
// 0xdbce40 HeapTripleTableDeallocators::Deletedbce40
// 0xdbcf90 HeapTripleTableDeallocators::Deletedbcf90
// 0xdbef50 HeapTripleTableDeallocators::Deletedbef50
// 0xdbf0b0 HeapTripleTableDeallocators::Deletedbf0b0
// 0xdbff90 HeapTripleTableDeallocators::Deletedbff90
// 0xdc0180 HeapTripleTableDeallocators::Deletedc0180
// 0xdc2810 HeapTripleTableDeallocators::Deletedc2810
// 0xdc2960 HeapTripleTableDeallocators::Deletedc2960
// 0xdc3f00 HeapTripleTableDeallocators::Deletedc3f00
// 0xdc4050 HeapTripleTableDeallocators::Deletedc4050
// 0xdc6a30 HeapTripleTableDeallocators::Deletedc6a30
// 0xdc6b80 HeapTripleTableDeallocators::Deletedc6b80
// 0xdcce30 HeapTripleTableDeallocators::Deletedcce30
// 0xdcd0d0 HeapTripleTableDeallocators::Deletedcd0d0
// 0xdd1a00 HeapTripleTableDeallocators::Deletedd1a00
// 0xdd1b50 HeapTripleTableDeallocators::Deletedd1b50
#include "HeapTripleTableDeallocators.h"

void* HeapTripleTableDeallocators::Deleted11b80(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a28148;
    object->table1 = TableTarget1a28190;
    object->table2 = TableTarget1a28238;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleted11d70(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a28148;
    object->table1 = TableTarget1a28190;
    object->table2 = TableTarget1a28238;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleted6b220(HeapTripleTableDeallocatorsTripleTableObject20_98* object, unsigned int flags)
{
    object->table0 = TableTarget1a2c760;
    object->table1 = TableTarget1a2c7a8;
    object->table2 = TableTarget1a2c850;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd6b0d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 216ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleted6b370(HeapTripleTableDeallocatorsTripleTableObject20_98* object, unsigned int flags)
{
    object->table0 = TableTarget1a2c760;
    object->table1 = TableTarget1a2c7a8;
    object->table2 = TableTarget1a2c850;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd6b0d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 216ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleted876e0(HeapTripleTableDeallocatorsTripleTableObject20_78* object, unsigned int flags)
{
    object->table0 = TableTarget1a2e9e0;
    object->table1 = TableTarget1a2ea28;
    object->table2 = TableTarget1a2ead0;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 184ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleted87830(HeapTripleTableDeallocatorsTripleTableObject20_78* object, unsigned int flags)
{
    object->table0 = TableTarget1a2e9e0;
    object->table1 = TableTarget1a2ea28;
    object->table2 = TableTarget1a2ead0;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 184ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleteda27c0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a30ee8;
    object->table1 = TableTarget1a30f30;
    object->table2 = TableTarget1a30fd8;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleteda2910(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a30ee8;
    object->table1 = TableTarget1a30f30;
    object->table2 = TableTarget1a30fd8;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleteda4d10(HeapTripleTableDeallocatorsTripleTableObject20_88* object, unsigned int flags)
{
    object->table0 = TableTarget1a31360;
    object->table1 = TableTarget1a313a8;
    object->table2 = TableTarget1a31450;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 200ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleteda4e60(HeapTripleTableDeallocatorsTripleTableObject20_88* object, unsigned int flags)
{
    object->table0 = TableTarget1a31360;
    object->table1 = TableTarget1a313a8;
    object->table2 = TableTarget1a31450;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 200ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleteda8350(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a31a40;
    object->table1 = TableTarget1a31a88;
    object->table2 = TableTarget1a31b30;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deleteda84a0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a31a40;
    object->table1 = TableTarget1a31a88;
    object->table2 = TableTarget1a31b30;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedaa750(HeapTripleTableDeallocatorsTripleTableObject20_90* object, unsigned int flags)
{
    object->table0 = TableTarget1a31ea0;
    object->table1 = TableTarget1a31ee8;
    object->table2 = TableTarget1a31f90;
    CleanupTargetd11840(&object->table2);
    CleanupTargetdaa660(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 208ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedaa8a0(HeapTripleTableDeallocatorsTripleTableObject20_90* object, unsigned int flags)
{
    object->table0 = TableTarget1a31ea0;
    object->table1 = TableTarget1a31ee8;
    object->table2 = TableTarget1a31f90;
    CleanupTargetd11840(&object->table2);
    CleanupTargetdaa660(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 208ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedaecf0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a328c8;
    object->table1 = TableTarget1a32910;
    object->table2 = TableTarget1a329b8;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedaee40(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a328c8;
    object->table1 = TableTarget1a32910;
    object->table2 = TableTarget1a329b8;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedb0340(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a32d90;
    object->table1 = TableTarget1a32dd8;
    object->table2 = TableTarget1a32e80;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedb0490(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a32d90;
    object->table1 = TableTarget1a32dd8;
    object->table2 = TableTarget1a32e80;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedb5ee0(HeapTripleTableDeallocatorsTripleTableObject20_70* object, unsigned int flags)
{
    object->table0 = TableTarget1a33d30;
    object->table1 = TableTarget1a33d78;
    object->table2 = TableTarget1a33e20;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 176ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedb6030(HeapTripleTableDeallocatorsTripleTableObject20_70* object, unsigned int flags)
{
    object->table0 = TableTarget1a33d30;
    object->table1 = TableTarget1a33d78;
    object->table2 = TableTarget1a33e20;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 176ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedb79b0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a342a8;
    object->table1 = TableTarget1a342f0;
    object->table2 = TableTarget1a34398;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedb7b00(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a342a8;
    object->table1 = TableTarget1a342f0;
    object->table2 = TableTarget1a34398;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedb8ba0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a347b0;
    object->table1 = TableTarget1a347f8;
    object->table2 = TableTarget1a348a0;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedb8cf0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a347b0;
    object->table1 = TableTarget1a347f8;
    object->table2 = TableTarget1a348a0;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedbce40(HeapTripleTableDeallocatorsTripleTableObject20_98* object, unsigned int flags)
{
    object->table0 = TableTarget1a35148;
    object->table1 = TableTarget1a35190;
    object->table2 = TableTarget1a35238;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 216ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedbcf90(HeapTripleTableDeallocatorsTripleTableObject20_98* object, unsigned int flags)
{
    object->table0 = TableTarget1a35148;
    object->table1 = TableTarget1a35190;
    object->table2 = TableTarget1a35238;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 216ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedbef50(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a356c0;
    object->table1 = TableTarget1a35708;
    object->table2 = TableTarget1a357b0;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedbf0b0(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a356c0;
    object->table1 = TableTarget1a35708;
    object->table2 = TableTarget1a357b0;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedbff90(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a35cb0;
    object->table1 = TableTarget1a35cf8;
    object->table2 = TableTarget1a35da0;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedc0180(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a35cb0;
    object->table1 = TableTarget1a35cf8;
    object->table2 = TableTarget1a35da0;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedc2810(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a36280;
    object->table1 = TableTarget1a362c8;
    object->table2 = TableTarget1a36370;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedc2960(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a36280;
    object->table1 = TableTarget1a362c8;
    object->table2 = TableTarget1a36370;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedc3f00(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a36850;
    object->table1 = TableTarget1a36898;
    object->table2 = TableTarget1a36940;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedc4050(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a36850;
    object->table1 = TableTarget1a36898;
    object->table2 = TableTarget1a36940;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedc6a30(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a36e48;
    object->table1 = TableTarget1a36e90;
    object->table2 = TableTarget1a36f38;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedc6b80(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a36e48;
    object->table1 = TableTarget1a36e90;
    object->table2 = TableTarget1a36f38;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedcce30(HeapTripleTableDeallocatorsTripleTableObject20_78* object, unsigned int flags)
{
    object->table0 = TableTarget1a37858;
    object->table1 = TableTarget1a378a0;
    object->table2 = TableTarget1a37948;
    CleanupTargetd11840(&object->table2);
    CleanupTargetdccc40(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 184ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedcd0d0(HeapTripleTableDeallocatorsTripleTableObject20_78* object, unsigned int flags)
{
    object->table0 = TableTarget1a37858;
    object->table1 = TableTarget1a378a0;
    object->table2 = TableTarget1a37948;
    CleanupTargetd11840(&object->table2);
    CleanupTargetdccc40(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 184ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedd1a00(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a385d0;
    object->table1 = TableTarget1a38618;
    object->table2 = TableTarget1a386c0;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}

void* HeapTripleTableDeallocators::Deletedd1b50(HeapTripleTableDeallocatorsTripleTableObject20_68* object, unsigned int flags)
{
    object->table0 = TableTarget1a385d0;
    object->table1 = TableTarget1a38618;
    object->table2 = TableTarget1a386c0;
    CleanupTargetd11840(&object->table2);
    CleanupTargetd116d0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 168ull);
        }
    }
    return object;
}
