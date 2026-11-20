// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45b010, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45b010 LeafAddress45b010::Address
#include "LeafAddress45b010.h"
extern unsigned char leaf_global;
void* LeafAddress45b010::Address() { return &leaf_global; }
