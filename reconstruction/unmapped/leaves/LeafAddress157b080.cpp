// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress157b080, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x157b080 LeafAddress157b080::Address
#include "LeafAddress157b080.h"
extern unsigned char leaf_global;
void* LeafAddress157b080::Address() { return &leaf_global; }
