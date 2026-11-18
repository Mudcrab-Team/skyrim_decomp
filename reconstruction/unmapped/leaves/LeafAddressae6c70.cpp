// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6c70, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6c70 LeafAddressae6c70::Address
#include "LeafAddressae6c70.h"
extern unsigned char leaf_global;
void* LeafAddressae6c70::Address() { return &leaf_global; }
