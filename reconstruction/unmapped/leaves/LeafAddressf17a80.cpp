// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf17a80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf17a80 LeafAddressf17a80::Address
#include "LeafAddressf17a80.h"
extern unsigned char leaf_global;
void* LeafAddressf17a80::Address() { return &leaf_global; }
