// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45b000, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45b000 LeafAddress45b000::Address
#include "LeafAddress45b000.h"
extern unsigned char leaf_global;
void* LeafAddress45b000::Address() { return &leaf_global; }
