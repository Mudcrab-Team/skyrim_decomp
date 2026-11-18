// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c9c0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c9c0 LeafAddressb9c9c0::Address
#include "LeafAddressb9c9c0.h"
extern unsigned char leaf_global;
void* LeafAddressb9c9c0::Address() { return &leaf_global; }
