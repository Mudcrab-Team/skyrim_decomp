// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress45aff0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x45aff0 LeafAddress45aff0::Address
#include "LeafAddress45aff0.h"
extern unsigned char leaf_global;
void* LeafAddress45aff0::Address() { return &leaf_global; }
