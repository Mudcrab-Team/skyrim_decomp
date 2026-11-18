// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf7bea0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf7bea0 LeafAddressf7bea0::Address
#include "LeafAddressf7bea0.h"
extern unsigned char leaf_global;
void* LeafAddressf7bea0::Address() { return &leaf_global; }
