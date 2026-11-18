// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5fe0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5fe0 LeafAddressae5fe0::Address
#include "LeafAddressae5fe0.h"
extern unsigned char leaf_global;
void* LeafAddressae5fe0::Address() { return &leaf_global; }
