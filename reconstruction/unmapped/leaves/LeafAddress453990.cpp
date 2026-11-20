// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress453990, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x453990 LeafAddress453990::Address
#include "LeafAddress453990.h"
extern unsigned char leaf_global;
void* LeafAddress453990::Address() { return &leaf_global; }
