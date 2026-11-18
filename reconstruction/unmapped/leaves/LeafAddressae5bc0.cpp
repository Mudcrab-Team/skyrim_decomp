// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5bc0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5bc0 LeafAddressae5bc0::Address
#include "LeafAddressae5bc0.h"
extern unsigned char leaf_global;
void* LeafAddressae5bc0::Address() { return &leaf_global; }
