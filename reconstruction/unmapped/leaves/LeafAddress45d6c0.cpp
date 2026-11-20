// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45d6c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45d6c0 LeafAddress45d6c0::Address
#include "LeafAddress45d6c0.h"
extern unsigned char leaf_global;
void* LeafAddress45d6c0::Address() { return &leaf_global; }
