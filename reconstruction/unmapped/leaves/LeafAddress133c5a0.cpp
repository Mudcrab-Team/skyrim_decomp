// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress133c5a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x133c5a0 LeafAddress133c5a0::Address
#include "LeafAddress133c5a0.h"
extern unsigned char leaf_global;
void* LeafAddress133c5a0::Address() { return &leaf_global; }
