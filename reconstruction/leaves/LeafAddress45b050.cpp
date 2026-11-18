// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45b050, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45b050 LeafAddress45b050::Address
#include "LeafAddress45b050.h"
extern unsigned char leaf_global;
void* LeafAddress45b050::Address() { return &leaf_global; }
