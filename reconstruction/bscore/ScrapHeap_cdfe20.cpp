// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ScrapHeap: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioncdfe20: GUESS(low); provisional member name
// 0xcdfe20 ScrapHeap::Functioncdfe20
// CI hash: 0xcdfe20 ?Functioncdfe20@ScrapHeap@@QEAAXXZ
#include "ScrapHeap_cdfe20.h"

// Guess: Trim committed pages after splitting or removing the trailing free block.
void ScrapHeap::Functioncdfe20()
{
    if(!flags && head->size>=0) {
        Blockcdfe20* block=head;
        std::uintptr_t aligned=(reinterpret_cast<std::uintptr_t>(block)+65535) & ~std::uintptr_t(65535);
        if(aligned<end && aligned-base>minimum) {
            std::size_t gap=aligned-reinterpret_cast<std::uintptr_t>(block);
            if(!gap) { head=block->next; Remove(block); }
            else {
                if(gap<32) { return; }
                Remove(block);
                block->size=gap-16;
                Insert(block);
            }
            Releasecdfe20(reinterpret_cast<void*>(aligned),end-aligned,0x4000);
            end=aligned;
        }
    }
}
