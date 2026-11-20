// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45afa0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45afa0 LeafAddress45afa0::Address
#include "LeafAddress45afa0.h"
extern unsigned char leaf_global;
void* LeafAddress45afa0::Address() { return &leaf_global; }
