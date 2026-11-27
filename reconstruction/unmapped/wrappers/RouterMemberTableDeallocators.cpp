// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original Havok TLS-router scalar deleting destructor wrappers.
// RouterMemberTableDeallocators, types, methods and referenced globals: GUESS(low) STANDIN CRASHLOGGER_PDB(59818@2026.10.24); original ownership unknown.
// Adapted bodies: none
// 0xaaa370 RouterMemberTableDeallocators::Deleteaaa370
// 0xae4800 RouterMemberTableDeallocators::Deleteae4800
// 0xae4890 RouterMemberTableDeallocators::Deleteae4890
// 0xae4920 RouterMemberTableDeallocators::Deleteae4920
// 0xae55e0 RouterMemberTableDeallocators::Deleteae55e0
// 0xae5670 RouterMemberTableDeallocators::Deleteae5670
// 0xb2e460 RouterMemberTableDeallocators::Deleteb2e460
// 0xb2e700 RouterMemberTableDeallocators::Deleteb2e700
// 0xb2eb20 RouterMemberTableDeallocators::Deleteb2eb20
// 0xca1d40 RouterMemberTableDeallocators::Deleteca1d40
// 0xcc8180 RouterMemberTableDeallocators::Deletecc8180
// 0x10d1d00 RouterMemberTableDeallocators::Delete10d1d00
// 0x10d2320 RouterMemberTableDeallocators::Delete10d2320
// CI hash: 0xaaa370 ?Deleteaaa370@RouterMemberTableDeallocators@@SAPEAXPEAUStringAt10Object@@I@Z
// CI hash: 0xae4800 ?Deleteae4800@RouterMemberTableDeallocators@@SAPEAXPEAUStringAt10Object@@I@Z
// CI hash: 0xae4890 ?Deleteae4890@RouterMemberTableDeallocators@@SAPEAXPEAUStringAt10Object@@I@Z
// CI hash: 0xae4920 ?Deleteae4920@RouterMemberTableDeallocators@@SAPEAXPEAUStringAt10Object@@I@Z
// CI hash: 0xae55e0 ?Deleteae55e0@RouterMemberTableDeallocators@@SAPEAXPEAUStringAt10Object@@I@Z
// CI hash: 0xae5670 ?Deleteae5670@RouterMemberTableDeallocators@@SAPEAXPEAUStringAt10Object@@I@Z
// CI hash: 0xb2e460 ?Deleteb2e460@RouterMemberTableDeallocators@@SAPEAXPEAUSubobjectAt18Object@@I@Z
// CI hash: 0xb2e700 ?Deleteb2e700@RouterMemberTableDeallocators@@SAPEAXPEAUSubobjectAt18Object@@I@Z
// CI hash: 0xb2eb20 ?Deleteb2eb20@RouterMemberTableDeallocators@@SAPEAXPEAUSubobjectAt10Object@@I@Z
// CI hash: 0xca1d40 ?Deleteca1d40@RouterMemberTableDeallocators@@SAPEAXPEAUStringAt20Object@@I@Z
// CI hash: 0xcc8180 ?Deletecc8180@RouterMemberTableDeallocators@@SAPEAXPEAUSubobjectAt10Object@@I@Z
// CI hash: 0x10d1d00 ?Delete10d1d00@RouterMemberTableDeallocators@@SAPEAXPEAUStringAt18Object@@I@Z
// CI hash: 0x10d2320 ?Delete10d2320@RouterMemberTableDeallocators@@SAPEAXPEAUStringAt18Object@@I@Z
#include "RouterMemberTableDeallocators.h"

// CrashLogger PDB records deleting destructors with 0-arg void() prototypes; MSVC x64 scalar
// deleting destructors take (this, deleteFlags) and return this.
namespace
{

constexpr unsigned int kDeleteMemoryFlag = 1u;
constexpr unsigned int kGlobalDeleteFlag = 4u;
constexpr unsigned short kDynamicAllocSizeTag = 0xffffu;

template <typename ObjectType, typename MemberType>
inline void* DestroyMemberAndRelease(
    ObjectType* object,
    void (*destroyMember)(MemberType*),
    unsigned int deleteFlags,
    unsigned long long objectSize)
{
    destroyMember(&object->member);
    object->vftable = kReferencedObjectVftable;
    if ((deleteFlags & kDeleteMemoryFlag) != 0u)
    {
        if ((deleteFlags & kGlobalDeleteFlag) == 0u)
        {
            unsigned short taggedSize = object->memSizeAndFlags;
            int allocSize = (taggedSize == kDynamicAllocSizeTag) ? static_cast<int>(objectSize) : taggedSize;
            RouterTableMemoryRouter* router = static_cast<RouterTableMemoryRouter*>(g_tlsGetValue(g_memoryRouterTlsSlot));
            router->heap->BlockFree(object, allocSize);
        }
        else
        {
            GlobalSizedDelete(object, objectSize);
        }
    }
    return object;
}

} // namespace

void* RouterMemberTableDeallocators::Deleteaaa370(StringAt10Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedStringPtr, deleteFlags, 24ull);
}

void* RouterMemberTableDeallocators::Deleteae4800(StringAt10Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedStringPtr, deleteFlags, 24ull);
}

void* RouterMemberTableDeallocators::Deleteae4890(StringAt10Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedStringPtr, deleteFlags, 32ull);
}

void* RouterMemberTableDeallocators::Deleteae4920(StringAt10Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedStringPtr, deleteFlags, 32ull);
}

void* RouterMemberTableDeallocators::Deleteae55e0(StringAt10Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedStringPtr, deleteFlags, 24ull);
}

void* RouterMemberTableDeallocators::Deleteae5670(StringAt10Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedStringPtr, deleteFlags, 24ull);
}

void* RouterMemberTableDeallocators::Deleteb2e460(SubobjectAt18Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedSubobjectB, deleteFlags, 48ull);
}

void* RouterMemberTableDeallocators::Deleteb2e700(SubobjectAt18Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedSubobjectB, deleteFlags, 56ull);
}

void* RouterMemberTableDeallocators::Deleteb2eb20(SubobjectAt10Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedSubobjectB, deleteFlags, 48ull);
}

void* RouterMemberTableDeallocators::Deleteca1d40(StringAt20Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedStringPtr, deleteFlags, 40ull);
}

void* RouterMemberTableDeallocators::Deletecc8180(SubobjectAt10Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedSubobjectC, deleteFlags, 88ull);
}

void* RouterMemberTableDeallocators::Delete10d1d00(StringAt18Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedStringPtr, deleteFlags, 48ull);
}

void* RouterMemberTableDeallocators::Delete10d2320(StringAt18Object* object, unsigned int deleteFlags)
{
    return DestroyMemberAndRelease(object, &DestroyOwnedStringPtr, deleteFlags, 32ull);
}
