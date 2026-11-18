// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress3e12a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x3e12a0 LeafAddress3e12a0::Address
#include "LeafAddress3e12a0.h"
extern unsigned char leaf_global;
void* LeafAddress3e12a0::Address() { return &leaf_global; }
