// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6660, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6660 LeafAddressae6660::Address
#include "LeafAddressae6660.h"
extern unsigned char leaf_global;
void* LeafAddressae6660::Address() { return &leaf_global; }
