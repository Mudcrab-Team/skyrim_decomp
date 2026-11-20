// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6e80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6e80 LeafAddressae6e80::Address
#include "LeafAddressae6e80.h"
extern unsigned char leaf_global;
void* LeafAddressae6e80::Address() { return &leaf_global; }
