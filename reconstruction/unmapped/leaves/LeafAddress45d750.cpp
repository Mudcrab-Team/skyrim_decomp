// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45d750, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45d750 LeafAddress45d750::Address
#include "LeafAddress45d750.h"
extern unsigned char leaf_global;
void* LeafAddress45d750::Address() { return &leaf_global; }
