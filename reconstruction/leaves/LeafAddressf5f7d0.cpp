// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf5f7d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf5f7d0 LeafAddressf5f7d0::Address
#include "LeafAddressf5f7d0.h"
extern unsigned char leaf_global;
void* LeafAddressf5f7d0::Address() { return &leaf_global; }
