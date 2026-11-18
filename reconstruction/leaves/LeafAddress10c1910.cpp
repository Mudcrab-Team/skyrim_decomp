// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10c1910, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10c1910 LeafAddress10c1910::Address
#include "LeafAddress10c1910.h"
extern unsigned char leaf_global;
void* LeafAddress10c1910::Address() { return &leaf_global; }
