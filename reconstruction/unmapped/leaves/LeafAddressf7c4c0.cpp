// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7c4c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7c4c0 LeafAddressf7c4c0::Address
#include "LeafAddressf7c4c0.h"
extern unsigned char leaf_global;
void* LeafAddressf7c4c0::Address() { return &leaf_global; }
