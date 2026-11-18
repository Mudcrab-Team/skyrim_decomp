// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12cc110, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12cc110 LeafAddress12cc110::Address
#include "LeafAddress12cc110.h"
extern unsigned char leaf_global;
void* LeafAddress12cc110::Address() { return &leaf_global; }
