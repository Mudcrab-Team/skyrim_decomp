// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5ae6f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5ae6f0 LeafAddress5ae6f0::Address
#include "LeafAddress5ae6f0.h"
extern unsigned char leaf_global;
void* LeafAddress5ae6f0::Address() { return &leaf_global; }
