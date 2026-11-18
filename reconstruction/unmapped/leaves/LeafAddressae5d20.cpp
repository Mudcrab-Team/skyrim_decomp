// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5d20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5d20 LeafAddressae5d20::Address
#include "LeafAddressae5d20.h"
extern unsigned char leaf_global;
void* LeafAddressae5d20::Address() { return &leaf_global; }
