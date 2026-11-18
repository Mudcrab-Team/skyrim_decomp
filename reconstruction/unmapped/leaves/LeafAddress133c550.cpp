// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress133c550, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x133c550 LeafAddress133c550::Address
#include "LeafAddress133c550.h"
extern unsigned char leaf_global;
void* LeafAddress133c550::Address() { return &leaf_global; }
