// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae60a0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae60a0 LeafAddressae60a0::Address
#include "LeafAddressae60a0.h"
extern unsigned char leaf_global;
void* LeafAddressae60a0::Address() { return &leaf_global; }
