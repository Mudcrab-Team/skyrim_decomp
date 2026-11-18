// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae67d0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae67d0 LeafAddressae67d0::Address
#include "LeafAddressae67d0.h"
extern unsigned char leaf_global;
void* LeafAddressae67d0::Address() { return &leaf_global; }
