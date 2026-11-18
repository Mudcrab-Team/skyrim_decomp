// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress3f4780, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x3f4780 LeafAddress3f4780::Address
#include "LeafAddress3f4780.h"
extern unsigned char leaf_global;
void* LeafAddress3f4780::Address() { return &leaf_global; }
