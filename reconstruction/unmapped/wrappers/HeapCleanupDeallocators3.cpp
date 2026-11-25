// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// HeapCleanupDeallocators3, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0xe188f0 HeapCleanupDeallocators3::Deletee188f0
// 0xe25560 HeapCleanupDeallocators3::Deletee25560
// 0xe255c0 HeapCleanupDeallocators3::Deletee255c0
// 0xe25620 HeapCleanupDeallocators3::Deletee25620
// 0xe25680 HeapCleanupDeallocators3::Deletee25680
// 0xe25930 HeapCleanupDeallocators3::Deletee25930
// 0xe25a50 HeapCleanupDeallocators3::Deletee25a50
// 0xe2c6d0 HeapCleanupDeallocators3::Deletee2c6d0
// 0xe3bcf0 HeapCleanupDeallocators3::Deletee3bcf0
// 0xe482b0 HeapCleanupDeallocators3::Deletee482b0
// 0xe48310 HeapCleanupDeallocators3::Deletee48310
// 0xe48370 HeapCleanupDeallocators3::Deletee48370
// 0xe50a90 HeapCleanupDeallocators3::Deletee50a90
// 0xe50af0 HeapCleanupDeallocators3::Deletee50af0
// 0xe55900 HeapCleanupDeallocators3::Deletee55900
// 0xe559c0 HeapCleanupDeallocators3::Deletee559c0
// 0xe59d90 HeapCleanupDeallocators3::Deletee59d90
// 0xe59df0 HeapCleanupDeallocators3::Deletee59df0
// 0xe59e50 HeapCleanupDeallocators3::Deletee59e50
// 0xe59eb0 HeapCleanupDeallocators3::Deletee59eb0
// 0xe59f10 HeapCleanupDeallocators3::Deletee59f10
// 0xe59f70 HeapCleanupDeallocators3::Deletee59f70
// 0xe59fd0 HeapCleanupDeallocators3::Deletee59fd0
// 0xe5a030 HeapCleanupDeallocators3::Deletee5a030
// 0xe5a090 HeapCleanupDeallocators3::Deletee5a090
// 0xe5a0f0 HeapCleanupDeallocators3::Deletee5a0f0
// 0xe5a150 HeapCleanupDeallocators3::Deletee5a150
// 0xe5a580 HeapCleanupDeallocators3::Deletee5a580
// 0xe692e0 HeapCleanupDeallocators3::Deletee692e0
// 0xe699f0 HeapCleanupDeallocators3::Deletee699f0
// 0xe69a50 HeapCleanupDeallocators3::Deletee69a50
// 0xe6c440 HeapCleanupDeallocators3::Deletee6c440
// 0xe6c5c0 HeapCleanupDeallocators3::Deletee6c5c0
// 0xe73be0 HeapCleanupDeallocators3::Deletee73be0
// 0xe7d580 HeapCleanupDeallocators3::Deletee7d580
// 0x1180a20 HeapCleanupDeallocators3::Delete1180a20
// 0x1180a80 HeapCleanupDeallocators3::Delete1180a80
// 0x1187c50 HeapCleanupDeallocators3::Delete1187c50
// 0x1187dc0 HeapCleanupDeallocators3::Delete1187dc0
// 0x1187e20 HeapCleanupDeallocators3::Delete1187e20
// 0x1187e80 HeapCleanupDeallocators3::Delete1187e80
// 0x1187ee0 HeapCleanupDeallocators3::Delete1187ee0
// 0x1187f40 HeapCleanupDeallocators3::Delete1187f40
#include "HeapCleanupDeallocators3.h"

void* HeapCleanupDeallocators3::Deletee188f0(void* object, unsigned int flags)
{
    CleanupTargete18110(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee25560(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 192ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee255c0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 152ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee25620(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee25680(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee25930(void* object, unsigned int flags)
{
    CleanupTargete25450(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee25a50(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee2c6d0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee3bcf0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee482b0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee48310(void* object, unsigned int flags)
{
    CleanupTargete47850(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 80ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee48370(void* object, unsigned int flags)
{
    CleanupTargete47980(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 464ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee50a90(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee50af0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee55900(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee559c0(void* object, unsigned int flags)
{
    CleanupTargetd163b0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 112ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee59d90(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee59df0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee59e50(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee59eb0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee59f10(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee59f70(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee59fd0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee5a030(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee5a090(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee5a0f0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee5a150(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee5a580(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 40ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee692e0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee699f0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee69a50(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee6c440(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee6c5c0(void* object, unsigned int flags)
{
    CleanupTargete6c390(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 40ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee73be0(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Deletee7d580(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Delete1180a20(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Delete1180a80(void* object, unsigned int flags)
{
    CleanupTargetcf3100(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Delete1187c50(void* object, unsigned int flags)
{
    CleanupTarget11a3dc0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 56ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Delete1187dc0(void* object, unsigned int flags)
{
    CleanupTargetd6dd80(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 192ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Delete1187e20(void* object, unsigned int flags)
{
    CleanupTarget1187710(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 2264ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Delete1187e80(void* object, unsigned int flags)
{
    CleanupTarget11a3e60(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 56ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Delete1187ee0(void* object, unsigned int flags)
{
    CleanupTarget1187a20(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 128ull);
        }
    }
    return object;
}

void* HeapCleanupDeallocators3::Delete1187f40(void* object, unsigned int flags)
{
    CleanupTarget1187ad0(object);
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            GlobalHeapSlot3275ae0->Free(object);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 224ull);
        }
    }
    return object;
}
