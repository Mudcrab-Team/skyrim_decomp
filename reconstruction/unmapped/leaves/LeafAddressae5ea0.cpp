// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5ea0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5ea0 LeafAddressae5ea0::Address
#include "LeafAddressae5ea0.h"
extern unsigned char leaf_global;
void* LeafAddressae5ea0::Address() { return &leaf_global; }
