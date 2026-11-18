// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6960, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6960 LeafAddressae6960::Address
#include "LeafAddressae6960.h"
extern unsigned char leaf_global;
void* LeafAddressae6960::Address() { return &leaf_global; }
