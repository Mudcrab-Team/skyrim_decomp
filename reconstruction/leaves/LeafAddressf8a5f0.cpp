// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf8a5f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf8a5f0 LeafAddressf8a5f0::Address
#include "LeafAddressf8a5f0.h"
extern unsigned char leaf_global;
void* LeafAddressf8a5f0::Address() { return &leaf_global; }
