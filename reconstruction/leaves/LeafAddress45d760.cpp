// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45d760, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45d760 LeafAddress45d760::Address
#include "LeafAddress45d760.h"
extern unsigned char leaf_global;
void* LeafAddress45d760::Address() { return &leaf_global; }
