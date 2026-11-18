// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10d2530, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10d2530 LeafAddress10d2530::Address
#include "LeafAddress10d2530.h"
extern unsigned char leaf_global;
void* LeafAddress10d2530::Address() { return &leaf_global; }
