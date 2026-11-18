// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45afe0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45afe0 LeafAddress45afe0::Address
#include "LeafAddress45afe0.h"
extern unsigned char leaf_global;
void* LeafAddress45afe0::Address() { return &leaf_global; }
