// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6d80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6d80 LeafAddressae6d80::Address
#include "LeafAddressae6d80.h"
extern unsigned char leaf_global;
void* LeafAddressae6d80::Address() { return &leaf_global; }
