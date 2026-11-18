// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6e20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6e20 LeafAddressae6e20::Address
#include "LeafAddressae6e20.h"
extern unsigned char leaf_global;
void* LeafAddressae6e20::Address() { return &leaf_global; }
