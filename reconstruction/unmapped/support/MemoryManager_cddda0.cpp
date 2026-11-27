// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_0086b820::Task0905::MemoryManager::GetHeapForPhysicalPointer.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00860000_o2.cpp:4573
// 0xcddda0 f3m_0086b820::Task0905::MemoryManager::GetHeapForPhysicalPointer
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00aa0000_od.cpp:754
#include "MemoryManager_cddda0.h"

namespace f3m_0086b820 {
namespace Task0905 {
Pool* MemoryManager::GetHeapForPhysicalPointer(void* memory) {
 Pool* found=0;
 for(unsigned short i=0;i<count && !found;i++) {
  if(pools[i]->Contains(memory)) found=pools[i];
 }
 return found;
}
}
}
