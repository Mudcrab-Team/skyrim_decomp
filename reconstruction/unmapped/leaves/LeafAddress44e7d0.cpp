// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress44e7d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x44e7d0 LeafAddress44e7d0::Address
#include "LeafAddress44e7d0.h"
extern unsigned char leaf_global;
void* LeafAddress44e7d0::Address() { return &leaf_global; }
