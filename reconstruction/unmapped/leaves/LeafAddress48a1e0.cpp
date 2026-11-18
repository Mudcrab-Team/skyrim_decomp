// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress48a1e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x48a1e0 LeafAddress48a1e0::Address
#include "LeafAddress48a1e0.h"
extern unsigned char leaf_global;
void* LeafAddress48a1e0::Address() { return &leaf_global; }
