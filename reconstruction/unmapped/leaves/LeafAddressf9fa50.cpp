// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf9fa50, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf9fa50 LeafAddressf9fa50::Address
#include "LeafAddressf9fa50.h"
extern unsigned char leaf_global;
void* LeafAddressf9fa50::Address() { return &leaf_global; }
