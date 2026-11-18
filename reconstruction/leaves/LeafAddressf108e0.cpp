// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf108e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf108e0 LeafAddressf108e0::Address
#include "LeafAddressf108e0.h"
extern unsigned char leaf_global;
void* LeafAddressf108e0::Address() { return &leaf_global; }
