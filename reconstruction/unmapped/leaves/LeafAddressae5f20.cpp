// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5f20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5f20 LeafAddressae5f20::Address
#include "LeafAddressae5f20.h"
extern unsigned char leaf_global;
void* LeafAddressae5f20::Address() { return &leaf_global; }
