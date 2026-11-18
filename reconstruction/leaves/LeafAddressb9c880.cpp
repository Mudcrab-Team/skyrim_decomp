// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressb9c880, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xb9c880 LeafAddressb9c880::Address
#include "LeafAddressb9c880.h"
extern unsigned char leaf_global;
void* LeafAddressb9c880::Address() { return &leaf_global; }
