// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf0f0f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf0f0f0 LeafAddressf0f0f0::Address
#include "LeafAddressf0f0f0.h"
extern unsigned char leaf_global;
void* LeafAddressf0f0f0::Address() { return &leaf_global; }
