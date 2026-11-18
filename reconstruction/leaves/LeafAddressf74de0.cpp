// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf74de0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf74de0 LeafAddressf74de0::Address
#include "LeafAddressf74de0.h"
extern unsigned char leaf_global;
void* LeafAddressf74de0::Address() { return &leaf_global; }
