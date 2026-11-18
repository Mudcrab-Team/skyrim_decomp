// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae62e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae62e0 LeafAddressae62e0::Address
#include "LeafAddressae62e0.h"
extern unsigned char leaf_global;
void* LeafAddressae62e0::Address() { return &leaf_global; }
