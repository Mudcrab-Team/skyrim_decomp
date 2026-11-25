// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Code origin: Stamped as a twin of matched 0xce8540 (bscore/MemoryHeap): source copied, names replaced by placeholders.
// Origin: anonymous sibling and target listing.
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryHeap.cpp:30
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryHeap.cpp:36
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryHeap.cpp:43
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryHeap.cpp:51
// 0x10e2660 Owner10e2660::Function10e2660
#include "Owner10e2660.h"

// guess: same compiled code as matched 0xce8540 apart from relocated fields; its role here is not established.
std::uint64_t Owner10e2660::Function10e2660(const void* pointer) const {
    const auto* header = reinterpret_cast<const std::uint64_t*>(static_cast<const char*>(pointer) - 32);
    return *header & 0x1fffffffffffffffULL;
}
