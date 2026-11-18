// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5ff900, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5ff900 LeafAddress5ff900::Address
#include "LeafAddress5ff900.h"
extern unsigned char leaf_global;
void* LeafAddress5ff900::Address() { return &leaf_global; }
