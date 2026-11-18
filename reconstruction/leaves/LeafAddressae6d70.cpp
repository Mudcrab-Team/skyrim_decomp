// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6d70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6d70 LeafAddressae6d70::Address
#include "LeafAddressae6d70.h"
extern unsigned char leaf_global;
void* LeafAddressae6d70::Address() { return &leaf_global; }
