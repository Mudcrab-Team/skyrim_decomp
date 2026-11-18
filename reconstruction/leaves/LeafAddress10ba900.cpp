// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10ba900, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10ba900 LeafAddress10ba900::Address
#include "LeafAddress10ba900.h"
extern unsigned char leaf_global;
void* LeafAddress10ba900::Address() { return &leaf_global; }
