// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae6450, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae6450 LeafAddressae6450::Address
#include "LeafAddressae6450.h"
extern unsigned char leaf_global;
void* LeafAddressae6450::Address() { return &leaf_global; }
