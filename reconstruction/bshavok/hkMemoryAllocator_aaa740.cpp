// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkMemoryAllocator::bufRealloc_1409CE7B0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/memory/allocator/hkmemoryallocator.cpp:108
// 0xaaa740 hkMemoryAllocator::bufRealloc_1409CE7B0
// CI hash: 0xaaa740 ?bufRealloc_1409CE7B0@hkMemoryAllocator@@QEAAPEAXPEAXHPEAUSFun00cbf280Args@@@Z
#include "hkMemoryAllocator_aaa740.h"

void* hkMemoryAllocator::bufRealloc_1409CE7B0(void* src, int size, SFun00cbf280Args* args)
{
    void* dest = this->Reserve(args);

    int count = args->limit;
    if (size < count)
        count = size;

    Func00d2caa0(dest, src, (unsigned int)count);

    this->Commit(src, size);

    return dest;
}
