// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf784f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf784f0 LeafAddressf784f0::Address
#include "LeafAddressf784f0.h"
extern unsigned char leaf_global;
void* LeafAddressf784f0::Address() { return &leaf_global; }
