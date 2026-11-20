// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5c50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5c50 LeafAddressae5c50::Address
#include "LeafAddressae5c50.h"
extern unsigned char leaf_global;
void* LeafAddressae5c50::Address() { return &leaf_global; }
