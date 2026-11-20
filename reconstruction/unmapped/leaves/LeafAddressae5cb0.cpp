// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressae5cb0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xae5cb0 LeafAddressae5cb0::Address
#include "LeafAddressae5cb0.h"
extern unsigned char leaf_global;
void* LeafAddressae5cb0::Address() { return &leaf_global; }
