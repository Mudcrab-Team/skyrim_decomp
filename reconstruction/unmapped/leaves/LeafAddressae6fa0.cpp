// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6fa0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6fa0 LeafAddressae6fa0::Address
#include "LeafAddressae6fa0.h"
extern unsigned char leaf_global;
void* LeafAddressae6fa0::Address() { return &leaf_global; }
