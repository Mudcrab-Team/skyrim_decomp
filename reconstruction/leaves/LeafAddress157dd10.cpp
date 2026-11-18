// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress157dd10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x157dd10 LeafAddress157dd10::Address
#include "LeafAddress157dd10.h"
extern unsigned char leaf_global;
void* LeafAddress157dd10::Address() { return &leaf_global; }
