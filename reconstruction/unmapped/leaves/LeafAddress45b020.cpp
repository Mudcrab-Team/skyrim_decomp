// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45b020, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45b020 LeafAddress45b020::Address
#include "LeafAddress45b020.h"
extern unsigned char leaf_global;
void* LeafAddress45b020::Address() { return &leaf_global; }
