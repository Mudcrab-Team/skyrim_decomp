// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5d50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5d50 LeafAddressae5d50::Address
#include "LeafAddressae5d50.h"
extern unsigned char leaf_global;
void* LeafAddressae5d50::Address() { return &leaf_global; }
