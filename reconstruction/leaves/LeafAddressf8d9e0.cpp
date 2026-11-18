// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf8d9e0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf8d9e0 LeafAddressf8d9e0::Address
#include "LeafAddressf8d9e0.h"
extern unsigned char leaf_global;
void* LeafAddressf8d9e0::Address() { return &leaf_global; }
