// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12859e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12859e0 LeafAddress12859e0::Address
#include "LeafAddress12859e0.h"
extern unsigned char leaf_global;
void* LeafAddress12859e0::Address() { return &leaf_global; }
