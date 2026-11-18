// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4769e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4769e0 LeafAddress4769e0::Address
#include "LeafAddress4769e0.h"
extern unsigned char leaf_global;
void* LeafAddress4769e0::Address() { return &leaf_global; }
