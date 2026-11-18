// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf714b0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf714b0 LeafAddressf714b0::Address
#include "LeafAddressf714b0.h"
extern unsigned char leaf_global;
void* LeafAddressf714b0::Address() { return &leaf_global; }
