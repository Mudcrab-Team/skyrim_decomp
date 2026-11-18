// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5d30, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5d30 LeafAddressae5d30::Address
#include "LeafAddressae5d30.h"
extern unsigned char leaf_global;
void* LeafAddressae5d30::Address() { return &leaf_global; }
