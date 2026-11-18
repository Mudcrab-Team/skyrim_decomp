// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfc22b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfc22b0 LeafAddressfc22b0::Address
#include "LeafAddressfc22b0.h"
extern unsigned char leaf_global;
void* LeafAddressfc22b0::Address() { return &leaf_global; }
