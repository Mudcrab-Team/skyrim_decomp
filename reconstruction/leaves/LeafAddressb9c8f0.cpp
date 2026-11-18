// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c8f0, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c8f0 LeafAddressb9c8f0::Address
#include "LeafAddressb9c8f0.h"
extern unsigned char leaf_global;
void* LeafAddressb9c8f0::Address() { return &leaf_global; }
