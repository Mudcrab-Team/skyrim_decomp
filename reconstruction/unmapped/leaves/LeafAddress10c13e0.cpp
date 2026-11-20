// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10c13e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10c13e0 LeafAddress10c13e0::Address
#include "LeafAddress10c13e0.h"
extern unsigned char leaf_global;
void* LeafAddress10c13e0::Address() { return &leaf_global; }
