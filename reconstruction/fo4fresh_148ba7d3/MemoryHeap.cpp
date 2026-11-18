// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// Allocate, Deallocate, Size, TotalSize: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryHeap.cpp:30
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryHeap.cpp:36
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryHeap.cpp:43
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryHeap.cpp:51
// 0xce8530 MemoryHeap::Deallocate
// 0xce8510 MemoryHeap::Allocate
// 0xce8540 MemoryHeap::Size
// 0xce8560 MemoryHeap::TotalSize
#include "MemoryHeap.h"
void* MemoryHeap::Allocate(std::uint64_t size, unsigned int alignment) { return BaseAllocate(size, alignment, true); }
void MemoryHeap::Deallocate(void* pointer, unsigned int) { if (pointer) BaseFree(pointer); }
std::uint64_t MemoryHeap::Size(const void* pointer) const {
    const auto* header = reinterpret_cast<const std::uint64_t*>(static_cast<const char*>(pointer) - 32);
    return *header & 0x1fffffffffffffffULL;
}
std::uint64_t MemoryHeap::TotalSize(const void* pointer) const {
    const auto* header = reinterpret_cast<const std::uint64_t*>(static_cast<const char*>(pointer) - 32);
    return ((*header & 0x1fffffffffffffffULL) + 15 & ~std::uint64_t(15)) + 32;
}
