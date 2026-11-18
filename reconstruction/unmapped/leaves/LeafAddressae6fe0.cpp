// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6fe0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6fe0 LeafAddressae6fe0::Address
#include "LeafAddressae6fe0.h"
extern unsigned char leaf_global;
void* LeafAddressae6fe0::Address() { return &leaf_global; }
