// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc499a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc499a0 LeafAddressc499a0::Address
#include "LeafAddressc499a0.h"
extern unsigned char leaf_global;
void* LeafAddressc499a0::Address() { return &leaf_global; }
