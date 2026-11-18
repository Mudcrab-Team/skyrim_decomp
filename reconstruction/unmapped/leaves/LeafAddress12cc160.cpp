// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress12cc160, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x12cc160 LeafAddress12cc160::Address
#include "LeafAddress12cc160.h"
extern unsigned char leaf_global;
void* LeafAddress12cc160::Address() { return &leaf_global; }
