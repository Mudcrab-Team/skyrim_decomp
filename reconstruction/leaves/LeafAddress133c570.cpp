// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress133c570, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x133c570 LeafAddress133c570::Address
#include "LeafAddress133c570.h"
extern unsigned char leaf_global;
void* LeafAddress133c570::Address() { return &leaf_global; }
