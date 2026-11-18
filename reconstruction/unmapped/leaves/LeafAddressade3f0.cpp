// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressade3f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xade3f0 LeafAddressade3f0::Address
#include "LeafAddressade3f0.h"
extern unsigned char leaf_global;
void* LeafAddressade3f0::Address() { return &leaf_global; }
