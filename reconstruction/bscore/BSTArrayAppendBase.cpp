// Source exposure: mixed (community allocator declarations and pinned image analysis).
// Code origin: original reconstruction of the append-index operation.
// BSTArrayAppendBase and AppendIndex: GUESS(medium) STANDIN; exact names unknown.
// IAllocatorFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xce0a20 ResearchLayouts::BSTArrayAppendBase::AppendIndex
// CI hash: 0xce0a20 ?AppendIndex@BSTArrayAppendBase@ResearchLayouts@@QEAAIAEAVIAllocatorFunctor@2@II@Z
#include "BSTArrayAppendBase.h"

namespace ResearchLayouts {
std::uint32_t BSTArrayAppendBase::AppendIndex(IAllocatorFunctor& allocator, std::uint32_t capacity,
                                             std::uint32_t elementSize)
{
    if (size < capacity) {
        return size++;
    }
    if (capacity == 0) {
        if (allocator.Allocate(capacity + 1, elementSize)) {
            size = 1;
            return 0;
        }
    } else if (allocator.Reallocate(size + 1, size, 0, 0, elementSize)) {
        return size++;
    }
    return static_cast<std::uint32_t>(-1);
}
}
