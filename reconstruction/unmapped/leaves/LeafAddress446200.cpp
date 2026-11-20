// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress446200, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x446200 LeafAddress446200::Address
#include "LeafAddress446200.h"
extern unsigned char leaf_global;
void* LeafAddress446200::Address() { return &leaf_global; }
