// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10bd160, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10bd160 LeafAddress10bd160::Address
#include "LeafAddress10bd160.h"
extern unsigned char leaf_global;
void* LeafAddress10bd160::Address() { return &leaf_global; }
