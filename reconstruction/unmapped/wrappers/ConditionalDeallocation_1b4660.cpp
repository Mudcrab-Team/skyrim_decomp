// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original conditional sized-deallocator template.
// ConditionalDeallocation_1b4660, wrapper methods and cleanup declarations: GUESS(low) STANDIN; original owners unknown.
// Adapted bodies: none
// 0x1b4660 ConditionalDeallocation_1b4660::Delete1b4660
// 0x419860 ConditionalDeallocation_1b4660::Delete419860
// 0x4f5070 ConditionalDeallocation_1b4660::Delete4f5070
// 0x4f8e20 ConditionalDeallocation_1b4660::Delete4f8e20
// 0x4f9100 ConditionalDeallocation_1b4660::Delete4f9100
// 0x4f96f0 ConditionalDeallocation_1b4660::Delete4f96f0
// 0x661e20 ConditionalDeallocation_1b4660::Delete661e20
// 0x769500 ConditionalDeallocation_1b4660::Delete769500
// 0xe12350 ConditionalDeallocation_1b4660::Deletee12350
// 0xeba640 ConditionalDeallocation_1b4660::Deleteeba640
// 0xec3f30 ConditionalDeallocation_1b4660::Deleteec3f30
// 0xf6a130 ConditionalDeallocation_1b4660::Deletef6a130
// 0x1259d40 ConditionalDeallocation_1b4660::Delete1259d40
// 0x1259da0 ConditionalDeallocation_1b4660::Delete1259da0
// 0x1283370 ConditionalDeallocation_1b4660::Delete1283370
// 0x12adf70 ConditionalDeallocation_1b4660::Delete12adf70
// 0x12adfd0 ConditionalDeallocation_1b4660::Delete12adfd0
// 0x12ae060 ConditionalDeallocation_1b4660::Delete12ae060
// 0x12bc650 ConditionalDeallocation_1b4660::Delete12bc650
// 0x12c99f0 ConditionalDeallocation_1b4660::Delete12c99f0
// 0x12c9a20 ConditionalDeallocation_1b4660::Delete12c9a20
// 0x1338d60 ConditionalDeallocation_1b4660::Delete1338d60
// 0x1338d90 ConditionalDeallocation_1b4660::Delete1338d90
// CI hash: 0x1b4660 ?Delete1b4660@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x419860 ?Delete419860@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x4f5070 ?Delete4f5070@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x4f8e20 ?Delete4f8e20@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x4f9100 ?Delete4f9100@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x4f96f0 ?Delete4f96f0@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x661e20 ?Delete661e20@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x769500 ?Delete769500@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0xe12350 ?Deletee12350@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0xeba640 ?Deleteeba640@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0xec3f30 ?Deleteec3f30@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0xf6a130 ?Deletef6a130@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x1259d40 ?Delete1259d40@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x1259da0 ?Delete1259da0@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x1283370 ?Delete1283370@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x12adf70 ?Delete12adf70@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x12adfd0 ?Delete12adfd0@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x12ae060 ?Delete12ae060@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x12bc650 ?Delete12bc650@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x12c99f0 ?Delete12c99f0@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x12c9a20 ?Delete12c9a20@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x1338d60 ?Delete1338d60@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
// CI hash: 0x1338d90 ?Delete1338d90@ConditionalDeallocation_1b4660@@SAPEAXPEAXI@Z
#include "ConditionalDeallocation_1b4660.h"

namespace {
constexpr unsigned int kDeallocateStorage = 0x1u;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Delete1b4660(void* object, unsigned int flags)
{
    CleanupTarget19f8d0(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 704ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Delete419860(void* object, unsigned int flags)
{
    CleanupTarget411280(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 712ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Delete4f5070(void* object, unsigned int flags)
{
    CleanupTarget4e3290(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 264ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Delete4f8e20(void* object, unsigned int flags)
{
    CleanupTarget4e3290(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 272ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Delete4f9100(void* object, unsigned int flags)
{
    CleanupTarget4e3290(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 256ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Delete4f96f0(void* object, unsigned int flags)
{
    CleanupTarget4e3290(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 256ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Delete661e20(void* object, unsigned int flags)
{
    CleanupTarget652600(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 624ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Delete769500(void* object, unsigned int flags)
{
    CleanupTarget740690(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 3056ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Deletee12350(void* object, unsigned int flags)
{
    CleanupTargete12230(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 216ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Deleteeba640(void* object, unsigned int flags)
{
    CleanupTargeteb95f0(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 400ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Deleteec3f30(void* object, unsigned int flags)
{
    CleanupTargeteaefb0(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 536ull);
    }
    return object;
}

// Run cleanup before the optional deallocation.
void* ConditionalDeallocation_1b4660::Deletef6a130(void* object, unsigned int flags)
{
    CleanupTargetf6b010(object);
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 120ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete1259d40(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete1259da0(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete1283370(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete12adf70(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete12adfd0(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete12ae060(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete12bc650(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete12c99f0(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete12c9a20(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete1338d60(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}

// Optionally free storage and return the original address.
void* ConditionalDeallocation_1b4660::Delete1338d90(void* object, unsigned int flags)
{
    if ((flags & kDeallocateStorage) != 0u)
    {
        ::operator delete(object, 8ull);
    }
    return object;
}
