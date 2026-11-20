// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf5d5d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf5d5d0 LeafAddressf5d5d0::Address
#include "LeafAddressf5d5d0.h"
extern unsigned char leaf_global;
void* LeafAddressf5d5d0::Address() { return &leaf_global; }
