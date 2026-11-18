// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6de0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6de0 LeafAddressae6de0::Address
#include "LeafAddressae6de0.h"
extern unsigned char leaf_global;
void* LeafAddressae6de0::Address() { return &leaf_global; }
