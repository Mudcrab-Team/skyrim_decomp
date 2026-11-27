// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkFreeList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionabc410: GUESS(low); provisional member name
// 0xabc410 hkFreeList::Functionabc410
// CI hash: 0xabc410 ?Functionabc410@hkFreeList@@QEAAXPEAUBlockabc410@@P6AXPEAX_KHH1@ZH1@Z
#include "hkFreeList_abc410.h"

// Guess: Visit every stored element in the allocator block chain.
void hkFreeList::Functionabc410(Blockabc410* block, void (*callback)(void*, std::size_t, int, int, void*), int mode, void* context)
{
    while (block) {
        char* item = block->data;
        char* end = item + block->count * elementSize;
        while (item < end) {
            callback(item, elementSize, 0, mode, context);
            item += elementSize;
        }
        block = block->next;
    }
}
