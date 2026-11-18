// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress4969e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x4969e0 LeafAddress4969e0::Address
#include "LeafAddress4969e0.h"
extern unsigned char leaf_global;
void* LeafAddress4969e0::Address() { return &leaf_global; }
