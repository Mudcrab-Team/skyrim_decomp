// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5eb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5eb0 LeafAddressae5eb0::Address
#include "LeafAddressae5eb0.h"
extern unsigned char leaf_global;
void* LeafAddressae5eb0::Address() { return &leaf_global; }
