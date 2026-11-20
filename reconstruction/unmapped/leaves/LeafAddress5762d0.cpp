// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5762d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5762d0 LeafAddress5762d0::Address
#include "LeafAddress5762d0.h"
extern unsigned char leaf_global;
void* LeafAddress5762d0::Address() { return &leaf_global; }
