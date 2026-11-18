// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49600, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49600 LeafAddressc49600::Address
#include "LeafAddressc49600.h"
extern unsigned char leaf_global;
void* LeafAddressc49600::Address() { return &leaf_global; }
