// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5dbed0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5dbed0 LeafAddress5dbed0::Address
#include "LeafAddress5dbed0.h"
extern unsigned char leaf_global;
void* LeafAddress5dbed0::Address() { return &leaf_global; }
