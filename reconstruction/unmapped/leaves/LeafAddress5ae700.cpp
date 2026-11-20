// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress5ae700, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x5ae700 LeafAddress5ae700::Address
#include "LeafAddress5ae700.h"
extern unsigned char leaf_global;
void* LeafAddress5ae700::Address() { return &leaf_global; }
