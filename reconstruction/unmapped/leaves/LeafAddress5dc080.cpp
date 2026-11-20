// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5dc080, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5dc080 LeafAddress5dc080::Address
#include "LeafAddress5dc080.h"
extern unsigned char leaf_global;
void* LeafAddress5dc080::Address() { return &leaf_global; }
