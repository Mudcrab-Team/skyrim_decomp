// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6e10, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6e10 LeafAddressae6e10::Address
#include "LeafAddressae6e10.h"
extern unsigned char leaf_global;
void* LeafAddressae6e10::Address() { return &leaf_global; }
