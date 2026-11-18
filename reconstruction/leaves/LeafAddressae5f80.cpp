// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5f80, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5f80 LeafAddressae5f80::Address
#include "LeafAddressae5f80.h"
extern unsigned char leaf_global;
void* LeafAddressae5f80::Address() { return &leaf_global; }
