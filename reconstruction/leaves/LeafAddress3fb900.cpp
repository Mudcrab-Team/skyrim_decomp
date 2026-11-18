// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress3fb900, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x3fb900 LeafAddress3fb900::Address
#include "LeafAddress3fb900.h"
extern unsigned char leaf_global;
void* LeafAddress3fb900::Address() { return &leaf_global; }
