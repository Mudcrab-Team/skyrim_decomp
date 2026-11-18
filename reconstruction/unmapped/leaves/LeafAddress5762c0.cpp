// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5762c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5762c0 LeafAddress5762c0::Address
#include "LeafAddress5762c0.h"
extern unsigned char leaf_global;
void* LeafAddress5762c0::Address() { return &leaf_global; }
