// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress3fb910, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x3fb910 LeafAddress3fb910::Address
#include "LeafAddress3fb910.h"
extern unsigned char leaf_global;
void* LeafAddress3fb910::Address() { return &leaf_global; }
