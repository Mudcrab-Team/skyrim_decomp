// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfa4990, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfa4990 LeafAddressfa4990::Address
#include "LeafAddressfa4990.h"
extern unsigned char leaf_global;
void* LeafAddressfa4990::Address() { return &leaf_global; }
