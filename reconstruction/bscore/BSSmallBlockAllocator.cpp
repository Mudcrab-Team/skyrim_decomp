// Code origin: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; names and declarations from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); no body is copied from any source; Functioncea520: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; names and declarations; Written for this reconstruction from the listing as an early-return range check; names from the existing header
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0xcea5a0 BSSmallBlockAllocator::TryAllocateImpl
// 0xcea710 BSSmallBlockAllocator::ContainsBlockImpl
// 0xcea3f0 BSSmallBlockAllocator::Size
// 0xcea520 BSSmallBlockAllocator::Functioncea520
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "BSSmallBlockAllocator.h"

void* BSSmallBlockAllocator::TryAllocateImpl(std::size_t a_size, std::uint32_t a_alignment)
{
    return AllocateInternal(a_size, a_alignment, false);
}

bool BSSmallBlockAllocator::ContainsBlockImpl(const void* a_block) const
{
    const char* block = static_cast<const char*>(a_block);
    return block >= allocBase && block < blockPageCommit;
}

std::size_t BSSmallBlockAllocator::Size(const void* a_block) const
{
    // Blocks live in 2 MiB mega pages measured from allocBase; each page's descriptor table gives the element size.
    const char* block = static_cast<const char*>(a_block);
    const std::ptrdiff_t offset = block - allocBase;
    const char* page = allocBase + (offset & ~(static_cast<std::ptrdiff_t>(sizeof(MegaBlockPage)) - 1));
    const MegaBlockPage* mega = reinterpret_cast<const MegaBlockPage*>(page);
    return mega->blockPages[(block - page) >> 13].elemSize;
}

// BSSmallBlockAllocator::Functioncea520: GUESS(low); early-return form of the range check, name is a placeholder
bool BSSmallBlockAllocator::Functioncea520(const void* a_block) const
{
    if (a_block < allocBase) {
        return false;
    }
    if (a_block >= blockPageCommit) {
        return false;
    }
    return true;
}
