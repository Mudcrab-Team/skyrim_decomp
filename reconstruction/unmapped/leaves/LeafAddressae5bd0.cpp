// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5bd0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5bd0 LeafAddressae5bd0::Address
#include "LeafAddressae5bd0.h"
extern unsigned char leaf_global;
void* LeafAddressae5bd0::Address() { return &leaf_global; }
