// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6ad0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6ad0 LeafAddressae6ad0::Address
#include "LeafAddressae6ad0.h"
extern unsigned char leaf_global;
void* LeafAddressae6ad0::Address() { return &leaf_global; }
