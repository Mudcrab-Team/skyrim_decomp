// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc499b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc499b0 LeafAddressc499b0::Address
#include "LeafAddressc499b0.h"
extern unsigned char leaf_global;
void* LeafAddressc499b0::Address() { return &leaf_global; }
