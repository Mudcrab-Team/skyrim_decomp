// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4390c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4390c0 LeafAddress4390c0::Address
#include "LeafAddress4390c0.h"
extern unsigned char leaf_global;
void* LeafAddress4390c0::Address() { return &leaf_global; }
