// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original custom-allocator deleting-destructor template.
// RouterFixedTableDeallocators, types, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// 0xadbc70 RouterFixedTableDeallocators::Deleteadbc70
// 0xadbcd0 RouterFixedTableDeallocators::Deleteadbcd0
// 0xadbfc0 RouterFixedTableDeallocators::Deleteadbfc0
// 0xb34180 RouterFixedTableDeallocators::Deleteb34180
// 0xb36eb0 RouterFixedTableDeallocators::Deleteb36eb0
// 0xb51dd0 RouterFixedTableDeallocators::Deleteb51dd0
// 0xb5cc70 RouterFixedTableDeallocators::Deleteb5cc70
// 0xb5cd50 RouterFixedTableDeallocators::Deleteb5cd50
// 0xb5cdb0 RouterFixedTableDeallocators::Deleteb5cdb0
// 0xb7cf70 RouterFixedTableDeallocators::Deleteb7cf70
// 0xc41520 RouterFixedTableDeallocators::Deletec41520
// 0xc7b8c0 RouterFixedTableDeallocators::Deletec7b8c0
// 0xc7b920 RouterFixedTableDeallocators::Deletec7b920
// 0xc7b980 RouterFixedTableDeallocators::Deletec7b980
// 0xc7b9e0 RouterFixedTableDeallocators::Deletec7b9e0
// 0x10dd230 RouterFixedTableDeallocators::Delete10dd230
// 0x10dd290 RouterFixedTableDeallocators::Delete10dd290
// 0x10dd2f0 RouterFixedTableDeallocators::Delete10dd2f0
// 0x1106d30 RouterFixedTableDeallocators::Delete1106d30
// 0x1123f20 RouterFixedTableDeallocators::Delete1123f20
// 0x1124400 RouterFixedTableDeallocators::Delete1124400
// 0x1126710 RouterFixedTableDeallocators::Delete1126710
// 0x1150f40 RouterFixedTableDeallocators::Delete1150f40
// 0x11514a0 RouterFixedTableDeallocators::Delete11514a0
// 0x1151500 RouterFixedTableDeallocators::Delete1151500
// 0x1151620 RouterFixedTableDeallocators::Delete1151620
// 0x1151860 RouterFixedTableDeallocators::Delete1151860
// 0x11518c0 RouterFixedTableDeallocators::Delete11518c0
// 0x1166af0 RouterFixedTableDeallocators::Delete1166af0
#include "RouterFixedTableDeallocators.h"

void* RouterFixedTableDeallocators::Deleteadbc70(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19c1168;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 16);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deleteadbcd0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19c1168;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 8);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 8ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deleteadbfc0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19c1168;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 16);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deleteb34180(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19e6638;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 8);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 8ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deleteb36eb0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19e6b78;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 8);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 8ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deleteb51dd0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19f2798;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 8);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 8ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deleteb5cc70(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19f4ef8;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 80);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 80ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deleteb5cd50(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19f4ef8;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 192);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 192ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deleteb5cdb0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19f4ef8;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 96);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 96ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deleteb7cf70(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19f5f20;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 8);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 8ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deletec41520(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a126a8;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 8);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 8ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deletec7b8c0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1867d68;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 16);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deletec7b920(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1867170;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 64);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 64ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deletec7b980(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1867d68;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 24);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 24ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Deletec7b9e0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1867170;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 48);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 48ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete10dd230(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19f4ed8;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 16);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete10dd290(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19f4ed8;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 16);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete10dd2f0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget19f4ed8;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 16);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete1106d30(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a97e28;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 16);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete1123f20(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a98488;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 64);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 64ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete1124400(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a98538;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 48);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 48ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete1126710(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget17fde30;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 48);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 48ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete1150f40(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a98ee8;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 16);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete11514a0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a98488;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 48);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 48ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete1151500(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a98f28;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 24);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 24ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete1151620(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a98488;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 96);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 96ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete1151860(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a98f28;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 16);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 16ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete11518c0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a990a8;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 8);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 8ull);
        }
    }
    return object;
}

void* RouterFixedTableDeallocators::Delete1166af0(RouterFixedTableDeallocatorsTableObject* object, unsigned int flags)
{
    object->table = TableTarget1a995f8;
    if ((flags & 1u) != 0u)
    {
        if ((flags & 4u) == 0u)
        {
            RouterFixedTableDeallocatorsMemoryRouter* router = static_cast<RouterFixedTableDeallocatorsMemoryRouter*>(TlsGetValueSlot17c8418(RouterTlsSlot325a844));
            router->heap->BlockFree(object, 160);
        }
        else
        {
            GlobalDeallocTarget1177a80(object, 160ull);
        }
    }
    return object;
}
