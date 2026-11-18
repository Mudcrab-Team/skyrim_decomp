// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45afd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45afd0 LeafAddress45afd0::Address
#include "LeafAddress45afd0.h"
extern unsigned char leaf_global;
void* LeafAddress45afd0::Address() { return &leaf_global; }
