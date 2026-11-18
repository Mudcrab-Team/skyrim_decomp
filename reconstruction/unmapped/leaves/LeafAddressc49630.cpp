// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressc49630, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xc49630 LeafAddressc49630::Address
#include "LeafAddressc49630.h"
extern unsigned char leaf_global;
void* LeafAddressc49630::Address() { return &leaf_global; }
