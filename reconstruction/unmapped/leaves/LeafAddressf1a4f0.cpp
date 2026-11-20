// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf1a4f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf1a4f0 LeafAddressf1a4f0::Address
#include "LeafAddressf1a4f0.h"
extern unsigned char leaf_global;
void* LeafAddressf1a4f0::Address() { return &leaf_global; }
