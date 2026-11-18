// Source exposure: binary-analysis; no external implementation reused.
// LeafAddress6076d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0x6076d0 LeafAddress6076d0::Address
#include "LeafAddress6076d0.h"
extern unsigned char leaf_global;
void* LeafAddress6076d0::Address() { return &leaf_global; }
