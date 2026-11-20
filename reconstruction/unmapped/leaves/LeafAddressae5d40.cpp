// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5d40, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5d40 LeafAddressae5d40::Address
#include "LeafAddressae5d40.h"
extern unsigned char leaf_global;
void* LeafAddressae5d40::Address() { return &leaf_global; }
