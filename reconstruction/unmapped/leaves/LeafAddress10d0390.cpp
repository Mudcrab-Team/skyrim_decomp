// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10d0390, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10d0390 LeafAddress10d0390::Address
#include "LeafAddress10d0390.h"
extern unsigned char leaf_global;
void* LeafAddress10d0390::Address() { return &leaf_global; }
