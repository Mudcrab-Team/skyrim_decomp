// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5d8900, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5d8900 LeafAddress5d8900::Address
#include "LeafAddress5d8900.h"
extern unsigned char leaf_global;
void* LeafAddress5d8900::Address() { return &leaf_global; }
