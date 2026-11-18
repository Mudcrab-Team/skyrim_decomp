// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc498a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc498a0 LeafAddressc498a0::Address
#include "LeafAddressc498a0.h"
extern unsigned char leaf_global;
void* LeafAddressc498a0::Address() { return &leaf_global; }
