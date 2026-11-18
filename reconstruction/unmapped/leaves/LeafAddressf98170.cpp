// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressf98170, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xf98170 LeafAddressf98170::Address
#include "LeafAddressf98170.h"
extern unsigned char leaf_global;
void* LeafAddressf98170::Address() { return &leaf_global; }
