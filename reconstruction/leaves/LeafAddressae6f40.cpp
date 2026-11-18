// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6f40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6f40 LeafAddressae6f40::Address
#include "LeafAddressae6f40.h"
extern unsigned char leaf_global;
void* LeafAddressae6f40::Address() { return &leaf_global; }
