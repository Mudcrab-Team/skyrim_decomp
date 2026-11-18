// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6650, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6650 LeafAddressae6650::Address
#include "LeafAddressae6650.h"
extern unsigned char leaf_global;
void* LeafAddressae6650::Address() { return &leaf_global; }
