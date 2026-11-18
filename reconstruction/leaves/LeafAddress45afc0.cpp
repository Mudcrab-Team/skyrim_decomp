// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45afc0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45afc0 LeafAddress45afc0::Address
#include "LeafAddress45afc0.h"
extern unsigned char leaf_global;
void* LeafAddress45afc0::Address() { return &leaf_global; }
