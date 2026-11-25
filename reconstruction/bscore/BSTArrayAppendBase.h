// Source exposure: mixed (community allocator declarations and pinned image analysis).
// Code origin: original reconstruction of the append-index operation.
// BSTArrayAppendBase and AppendIndex: GUESS(medium) STANDIN; exact names unknown.
// IAllocatorFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "ArrayAllocatorFunctorLayout.h"

namespace ResearchLayouts {
struct BSTArrayAppendBase {
    std::uint32_t size;

    std::uint32_t AppendIndex(IAllocatorFunctor& allocator, std::uint32_t capacity,
                              std::uint32_t elementSize);
};

static_assert(sizeof(BSTArrayAppendBase) == 4, "array size field");
}
