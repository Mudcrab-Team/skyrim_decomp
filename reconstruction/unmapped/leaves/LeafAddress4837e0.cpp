// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4837e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4837e0 LeafAddress4837e0::Address
#include "LeafAddress4837e0.h"
extern unsigned char leaf_global;
void* LeafAddress4837e0::Address() { return &leaf_global; }
