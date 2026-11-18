// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5cc0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5cc0 LeafAddressae5cc0::Address
#include "LeafAddressae5cc0.h"
extern unsigned char leaf_global;
void* LeafAddressae5cc0::Address() { return &leaf_global; }
