// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress10bd170, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x10bd170 LeafAddress10bd170::Address
#include "LeafAddress10bd170.h"
extern unsigned char leaf_global;
void* LeafAddress10bd170::Address() { return &leaf_global; }
