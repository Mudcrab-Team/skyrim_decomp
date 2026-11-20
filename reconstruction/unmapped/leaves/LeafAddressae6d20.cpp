// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6d20, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6d20 LeafAddressae6d20::Address
#include "LeafAddressae6d20.h"
extern unsigned char leaf_global;
void* LeafAddressae6d20::Address() { return &leaf_global; }
