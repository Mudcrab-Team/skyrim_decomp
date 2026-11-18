// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf1d6f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf1d6f0 LeafAddressf1d6f0::Address
#include "LeafAddressf1d6f0.h"
extern unsigned char leaf_global;
void* LeafAddressf1d6f0::Address() { return &leaf_global; }
