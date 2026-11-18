// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfc0db0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfc0db0 LeafAddressfc0db0::Address
#include "LeafAddressfc0db0.h"
extern unsigned char leaf_global;
void* LeafAddressfc0db0::Address() { return &leaf_global; }
