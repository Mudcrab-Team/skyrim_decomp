// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress485630, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x485630 LeafAddress485630::Address
#include "LeafAddress485630.h"
extern unsigned char leaf_global;
void* LeafAddress485630::Address() { return &leaf_global; }
