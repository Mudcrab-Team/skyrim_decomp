// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf6a1f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf6a1f0 LeafAddressf6a1f0::Address
#include "LeafAddressf6a1f0.h"
extern unsigned char leaf_global;
void* LeafAddressf6a1f0::Address() { return &leaf_global; }
