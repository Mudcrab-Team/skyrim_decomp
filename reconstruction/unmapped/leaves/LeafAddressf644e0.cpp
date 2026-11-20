// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf644e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf644e0 LeafAddressf644e0::Address
#include "LeafAddressf644e0.h"
extern unsigned char leaf_global;
void* LeafAddressf644e0::Address() { return &leaf_global; }
