// Source exposure: binary-analysis; no external implementation reused.
// LeafAddressfc0910, Address, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-address-leaf v1
// 0xfc0910 LeafAddressfc0910::Address
#include "LeafAddressfc0910.h"
extern unsigned char leaf_global;
void* LeafAddressfc0910::Address() { return &leaf_global; }
