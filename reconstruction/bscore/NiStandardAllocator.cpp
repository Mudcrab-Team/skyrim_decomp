// Source exposure: mixed (local binary analysis and public names).
// Code origin: written for this project from the pinned image listing; no body adapted.
// SPDX-License-Identifier: CC0-1.0
// 0xeafb10 NiStandardAllocator::Functioneafb10
// Adapted bodies: none.
// NiStandardAllocator: EXE_RTTI
// VerifyAddress: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0xeafd30 NiStandardAllocator::VerifyAddress
#include "NiStandardAllocator.h"
// VerifyAddress: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t NiStandardAllocator::VerifyAddress() const
{
    return 0x1;
}

// Functioneafb10: GUESS(low); guarded dispatch to the allocator body.
void NiStandardAllocator::Functioneafb10(void* a_mem, std::uint32_t a_alignment)
{
    if (!a_mem) {
        return;
    }
    if (a_alignment != 0x10) {
        if (g_allocatorInitFlag != 2) {
            NiStandardAllocatorInitThreadHeader(&g_allocatorInitObject, &g_allocatorInitFlag);
        }
        NiStandardAllocatorDispatch(&g_allocatorInitObject, a_mem, false);
    } else {
        if (g_allocatorInitFlag != 2) {
            NiStandardAllocatorInitThreadHeader(&g_allocatorInitObject, &g_allocatorInitFlag);
        }
        NiStandardAllocatorDispatch(&g_allocatorInitObject, a_mem, true);
    }
}
