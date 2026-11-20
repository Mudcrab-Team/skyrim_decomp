// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfe1de0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfe1de0 LeafAddressfe1de0::Address
#include "LeafAddressfe1de0.h"
extern unsigned char leaf_global;
void* LeafAddressfe1de0::Address() { return &leaf_global; }
