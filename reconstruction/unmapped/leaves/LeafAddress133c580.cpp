// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress133c580, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x133c580 LeafAddress133c580::Address
#include "LeafAddress133c580.h"
extern unsigned char leaf_global;
void* LeafAddress133c580::Address() { return &leaf_global; }
