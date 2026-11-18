// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7a9f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7a9f0 LeafAddressf7a9f0::Address
#include "LeafAddressf7a9f0.h"
extern unsigned char leaf_global;
void* LeafAddressf7a9f0::Address() { return &leaf_global; }
