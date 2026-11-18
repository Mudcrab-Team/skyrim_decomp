// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7a2d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7a2d0 LeafAddressf7a2d0::Address
#include "LeafAddressf7a2d0.h"
extern unsigned char leaf_global;
void* LeafAddressf7a2d0::Address() { return &leaf_global; }
