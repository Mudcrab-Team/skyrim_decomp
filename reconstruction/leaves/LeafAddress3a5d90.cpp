// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress3a5d90, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x3a5d90 LeafAddress3a5d90::Address
#include "LeafAddress3a5d90.h"
extern unsigned char leaf_global;
void* LeafAddress3a5d90::Address() { return &leaf_global; }
