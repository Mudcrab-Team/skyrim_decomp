// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c830, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c830 LeafAddressb9c830::Address
#include "LeafAddressb9c830.h"
extern unsigned char leaf_global;
void* LeafAddressb9c830::Address() { return &leaf_global; }
