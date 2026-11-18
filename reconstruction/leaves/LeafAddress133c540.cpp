// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress133c540, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x133c540 LeafAddress133c540::Address
#include "LeafAddress133c540.h"
extern unsigned char leaf_global;
void* LeafAddress133c540::Address() { return &leaf_global; }
