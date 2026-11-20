// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress242e80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x242e80 LeafAddress242e80::Address
#include "LeafAddress242e80.h"
extern unsigned char leaf_global;
void* LeafAddress242e80::Address() { return &leaf_global; }
