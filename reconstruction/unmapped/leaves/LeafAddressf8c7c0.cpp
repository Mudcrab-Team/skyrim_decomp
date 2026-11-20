// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf8c7c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf8c7c0 LeafAddressf8c7c0::Address
#include "LeafAddressf8c7c0.h"
extern unsigned char leaf_global;
void* LeafAddressf8c7c0::Address() { return &leaf_global; }
