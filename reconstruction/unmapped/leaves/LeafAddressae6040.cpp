// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6040, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6040 LeafAddressae6040::Address
#include "LeafAddressae6040.h"
extern unsigned char leaf_global;
void* LeafAddressae6040::Address() { return &leaf_global; }
