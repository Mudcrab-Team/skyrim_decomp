// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5bb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5bb0 LeafAddressae5bb0::Address
#include "LeafAddressae5bb0.h"
extern unsigned char leaf_global;
void* LeafAddressae5bb0::Address() { return &leaf_global; }
