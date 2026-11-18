// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4969a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4969a0 LeafAddress4969a0::Address
#include "LeafAddress4969a0.h"
extern unsigned char leaf_global;
void* LeafAddress4969a0::Address() { return &leaf_global; }
